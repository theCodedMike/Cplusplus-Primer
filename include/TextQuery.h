//
// Created by lixia on 2025/9/16.
//

#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <memory>
#include <sstream>
#include <map>
#include <set>
#include <utility>
using line_no = std::vector<std::string>::size_type;

class QueryResult {
    friend std::ostream & print(std::ostream &, const QueryResult &);

    std::string sought; // 待查询的单词
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;

public:
    QueryResult(std::string s,
        std::shared_ptr<std::set<line_no>> p,
        std::shared_ptr<std::vector<std::string>> f)
    : sought(std::move(s)), lines(std::move(p)), file(std::move(f)) {}
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
    [[nodiscard]] QueryResult query(const std::string &) const;
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
#endif //TEXTQUERY_H