//
// Created by lixia on 2025/9/16.
//

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <algorithm>
#include <fstream>
#include <memory>
#include <sstream>
#include <map>
#include <set>
#include <utility>
using line_no = std::vector<std::string>::size_type;
using line_it = std::set<line_no>::const_iterator;

class QueryResult {
    friend std::ostream & print(std::ostream &, const QueryResult &);

public:
    QueryResult(std::string s,
        std::shared_ptr<std::set<line_no>> p,
        std::shared_ptr<std::vector<std::string>> f)
    : sought(std::move(s)), lines(std::move(p)), file(std::move(f)) {}
    [[nodiscard]]
    auto size() const {
        return lines->size();
    }
    [[nodiscard]]
    auto begin() const {
        return lines->cbegin();
    }
    [[nodiscard]]
    auto end() const {
        return lines->cend();
    }
    std::shared_ptr<std::vector<std::string>> get_file() {
        return file;
    }
private:
    std::string sought; // 待查询的单词
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};


inline std::ostream & print(std::ostream & os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " " << (qr.lines->size() == 1 ? "time" : "times") << std::endl;

    for (const auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") " << qr.file->at(num) << std::endl;
    }

    return os;
}


class TextQuery {
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
public:
    explicit TextQuery(std::ifstream &);
    [[nodiscard]]
    QueryResult query(const std::string &) const;
};

// 读取输入文件并建立单词到行号的映射
inline TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>) {
    std::string text;

    while (std::getline(is, text)) {
        file->push_back(text);
        auto n = file->size() - 1; // 当前行号
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            auto & lines = wm[word];
            if (!lines)
                lines = std::make_shared<std::set<line_no>>();
            lines->insert(n);
        }
    }
}

inline QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    if (const auto loc = wm.find(sought); loc == wm.end())
        return {sought, nodata, file};
    else
        return {sought, loc->second, file};
}





// abstract class acts as a base class for concrete query type; all members are private
class Query_base {
    friend class Query;
protected:
    virtual ~Query_base() = default;
private:
    [[nodiscard]]
    virtual QueryResult eval(const TextQuery &) const = 0;
    [[nodiscard]]
    virtual std::string rep() const = 0;
};








// interface class to manage the Query_base inheritance hierarchy
class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    explicit Query(const std::string &s);
    [[nodiscard]]
    QueryResult eval(const TextQuery &t) const {
        return q->eval(t);
    }
    [[nodiscard]]
    std::string rep() const {
        return q->rep();
    }

private:
    std::shared_ptr<Query_base> q;

    Query(std::shared_ptr<Query_base> query) : q(std::move(query)) { }
};

inline std::ostream & operator<<(std::ostream &os, const Query &query) {
    os << query.rep();
    return os;
}







class WordQuery final : public Query_base {
    friend class Query;

private:
    explicit WordQuery(const std::string &s) : query_word(s) { }
    [[nodiscard]]
    QueryResult eval(const TextQuery &t) const override{
        return t.query(query_word);
    }
    [[nodiscard]]
    std::string rep() const override {
        return query_word;
    }

private:
    std::string query_word; // 待查找的单词
};

inline Query::Query(const std::string &s) : q(new WordQuery(s)) { }









class NotQuery final : public Query_base {
    friend Query operator~(const Query &);

private:
    explicit NotQuery(const Query &q) : query(q) {}
    [[nodiscard]]
    QueryResult eval(const TextQuery &) const override;
    [[nodiscard]]
    std::string rep() const override {
        return "~(" + query.rep() + ")";
    }

private:
    Query query;
};
inline QueryResult NotQuery::eval(const TextQuery & text) const {
    auto result = query.eval(text);

    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto beg = result.begin();
    const auto end = result.end();
    const auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }

    return {rep(), ret_lines, result.get_file()};
}










class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string opn) :
        lhs(l), rhs(r), op_name(std::move(opn)) { }

    [[nodiscard]]
    std::string rep() const override {
        return "(" + lhs.rep() + " " + op_name + " " + rhs.rep() + ")";
    }

protected:
    Query lhs, rhs;
    std::string op_name; // name of the operator
};










class AndQuery final : public BinaryQuery {
    friend Query operator&(const Query &, const Query &);

private:
    AndQuery(const Query &left, const Query &right) :
        BinaryQuery(left, right, "&") { }

    [[nodiscard]]
    QueryResult eval(const TextQuery &) const override;
};
inline QueryResult AndQuery::eval(const TextQuery & text) const {
    auto left = lhs.eval(text), right = rhs.eval(text);

    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::ranges::set_intersection(left, right,
                                  std::inserter(*ret_lines, ret_lines->begin()));

    return {rep(), ret_lines, left.get_file()};
}








class OrQuery final : public BinaryQuery {
    friend Query operator|(const Query &, const Query &);

private:
    OrQuery(const Query &left, const Query &right) :
        BinaryQuery(left, right, "|") { }

    [[nodiscard]]
    QueryResult eval(const TextQuery &) const override;
};
inline QueryResult OrQuery::eval(const TextQuery & text) const {
    const auto right = rhs.eval(text);
    auto left = lhs.eval(text);

    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());

    return {rep(), ret_lines, left.get_file()};
}









inline Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
inline Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
inline Query operator~(const Query & operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}


#endif //TEXTQUERY_H
