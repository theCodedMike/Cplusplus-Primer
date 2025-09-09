# C++ Primer
C++ Primer 学习笔记


## 附录A.2 算法概览
### A.2.1 查找对象的算法
<table>
    <tr>
        <th colspan="3">简单查找算法</th>
    </tr>
    <tr>
        <td>1</td> <td>find(beg, end, val) -> iterator</td> <td>指向输入序列中第1个等于val的元素，未找到时返回end</td>
    </tr>
    <tr>
        <td>2</td> <td>find_if(beg, end, unaryPred) -> iterator</td> <td>指向第1个满足unaryPred的元素</td>
    </tr>
    <tr>
        <td>3</td> <td>find_if_not(beg, end, unaryPred) -> iterator</td> <td>指向第1个令unaryPred为false的元素</td>
    </tr>
    <tr>
        <td>4</td> <td>count(beg, end, val) -> ptrdiff_t</td> <td></td>
    </tr>
    <tr>
        <td>5</td> <td>count_if(beg, end, unaryPred) -> ptrdiff_t</td> <td></td>
    </tr>
    <tr>
        <td>6</td> <td>all_of(beg, end, unaryPred) -> bool</td> <td></td>
    </tr>
    <tr>
        <td>7</td> <td>any_of(beg, end, unaryPred) -> bool</td> <td></td>
    </tr>
    <tr>
        <td>8</td> <td>none_of(beg, end, unaryPred) -> bool</td> <td></td>
    </tr>
    <tr>
        <th colspan="3">查找重复值的算法</th>
    </tr>
    <tr>
        <td>1</td> <td>adjacent_find(beg, end) -> iterator</td> <td>指向第1对相邻重复元素，未找到时返回end</td>
    </tr>
    <tr>
        <td>2</td> <td>adjacent_find(beg, end, unaryPred) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>search_n(beg, end, count, val) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>4</td> <td>search_n(beg, end, count, val, binaryPred) -> iterator</td> <td></td>
    </tr>
    <tr>
        <th colspan="3">查找子序列的算法</th>
    </tr>
    <tr>
        <td>1</td> <td>search(beg1, end1, beg2, end2) -> iterator</td> <td>第二个子序列第1次出现在第一个子序列的位置，未找到时返回end1</td>
    </tr>
    <tr>
        <td>2</td> <td>search(beg1, end1, beg2, end2, binaryPred) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>find_first_of(beg1, end1, beg2, end2) -> iterator</td> <td>第二个子序列的任意元素第1次出现在第一个子序列的位置，未找到时返回end1</td>
    </tr>
    <tr>
        <td>4</td> <td>find_first_of(beg1, end1, beg2, end2, binaryPred) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>5</td> <td>find_end(beg1, end1, beg2, end2) -> iterator</td> <td>第二个子序列最后一次出现在第一个子序列的位置，未找到时返回end1</td>
    </tr>
    <tr>
        <td>6</td> <td>find_end(beg1, end1, beg2, end2, binaryPred) -> iterator</td> <td></td>
    </tr>
</table>

### A.2.2 其他只读算法
<table>
    <tr>
        <td>1</td> <td>for_each(beg, end, unaryOp)</td> <td>对输入序列中的每个元素应用unaryOp</td>
    </tr>
    <tr>
        <td>2</td> <td>mismatch(beg1, end1, beg2)</td> <td>比较2个序列中的元素，返回一个迭代器的pair，表示2个序列中第1个不匹配的元素</td>
    </tr>
    <tr>
        <td>3</td> <td>mismatch(beg1, end1, beg2, binaryPred)</td> <td></td>
    </tr>
    <tr>
        <td>4</td> <td>equal(beg1, end1, beg2)</td> <td>比较2个序列是否相等</td>
    </tr>
    <tr>
        <td>5</td> <td>equal(beg1, end1, beg2, binaryPred)</td> <td></td>
    </tr>
</table>

### A.2.3 二分搜索算法
<table>
    <tr>
        <td>1</td> <td>lower_bound(beg, end, val) -> iterator</td> <td>返回第1个<=val的元素，如果不存在，返回end</td>
    </tr>
    <tr>
        <td>2</td> <td>lower_bound(beg, end, val, cmp) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>upper_bound(beg, end, val) -> iterator</td> <td>返回第1个>val的元素，如果不存在，返回end</td>
    </tr>
    <tr>
        <td>4</td> <td>upper_bound(beg, end, val, cmp) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>5</td> <td>equal_range(beg, end, val) -> pair</td> <td>lower_bound和upper_bound的混合结果</td>
    </tr>
    <tr>
        <td>6</td> <td>equal_range(beg, end, val, cmp) -> pair</td> <td></td>
    </tr>
    <tr>
        <td>7</td> <td>binary_search(beg, end, val) -> bool</td> <td></td>
    </tr>
    <tr>
        <td>8</td> <td>binary_search(beg, end, val, cmp) -> bool</td> <td></td>
    </tr>
</table>

### A.2.4 写容器元素的算法
<table>
    <tr>
        <th colspan="3">只写不读元素的算法</th>
    </tr>
    <tr>
        <td>1</td> <td>fill(beg, end, val)</td> <td>给输入序列中的每个元素赋予一个新值</td>
    </tr>
    <tr>
        <td>2</td> <td>fill_n(dest, cnt, val) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>generate(beg, end, Gen)</td> <td></td>
    </tr>
    <tr>
        <td>4</td> <td>generate_n(dest, cnt, Gen) -> iterator</td> <td></td>
    </tr>
    <tr>
        <th colspan="3">使用输入迭代器的写算法</th>
    </tr>
    <tr>
        <td>1</td> <td>copy(beg, end, dest)</td> <td>把输入范围的元素拷贝到dest指定的目标序列中</td>
    </tr>
    <tr>
        <td>2</td> <td>copy_if(beg, end, dest, unaryPred)</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>copy_n(beg, n, dest)</td> <td></td>
    </tr>
    <tr>
        <td>4</td> <td>move(beg, end, dest)</td> <td>对输入序列中的每个元素调用std::move</td>
    </tr>
    <tr>
        <td>5</td> <td>transform(beg, end, dest, unaryOp)</td> <td>调用给定操作，将结果写到dest中</td>
    </tr>
    <tr>
        <td>6</td> <td>transform(beg, end, beg2, dest, binaryOp)</td> <td></td>
    </tr>
    <tr>
        <td>7</td> <td>replace_copy(beg, end, dest, old_val, new_val)</td> <td>将每个元素拷贝到dest，将指定的元素替换为new_val</td>
    </tr>
    <tr>
        <td>8</td> <td>replace_copy_if(beg, end, dest, unaryPred, new_val)</td> <td></td>
    </tr>
    <tr>
        <td>9</td> <td>marge(beg1, end1, beg2, end2, dest)</td> <td>2个输入序列必须都是有序的，将合并后的序列写入到dest中</td>
    </tr>
    <tr>
        <td>10</td> <td>marge(beg1, end1, beg2, end2, dest, comp)</td> <td></td>
    </tr>
    <tr>
        <th colspan="3">使用前向迭代器的写算法</th>
    </tr>
    <tr>
        <td>1</td> <td>iter_swap(iter1, iter2)</td> <td>互换</td>
    </tr>
    <tr>
        <td>2</td> <td>swap_ranges(beg1, end1, beg2)</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>replace(beg, end, old_val, new_val)</td> <td>替换</td>
    </tr>
    <tr>
        <td>4</td> <td>replace_if(beg, end, unaryPred, new_val)</td> <td></td>
    </tr>
    <tr>
        <th colspan="3">使用双向迭代器的写算法</th>
    </tr>
    <tr>
        <td>1</td> <td>copy_backward(beg, end, dest)</td> <td>把输入范围中的元素拷贝到指定目的位置</td>
    </tr>
    <tr>
        <td>2</td> <td>move_backward(beg, end, dest)</td> <td>把输入范围中的元素移动到指定目的位置</td>
    </tr>
    <tr>
        <td>3</td> <td>inplace_merge(beg, mid, end)</td> <td>把同一个序列中的2个有序子序列合并为单一的有序序列</td>
    </tr>
    <tr>
        <td>4</td> <td>inplace_merge(beg, mid, end, comp)</td> <td></td>
    </tr>
</table>

### A.2.5 划分和排序算法
<table>
    <tr>
        <th colspan="3">划分算法</th>
    </tr>
    <tr>
        <td>1</td> <td>is_partitioned(beg, end, unaryPred) -> bool</td> <td></td>
    </tr>
    <tr>
        <td>2</td> <td>partition_copy(beg, end, dest1, dest2, unaryPred) -> pair</td> <td>将满足unaryPred的元素拷贝到dest1，把不满足的元素拷贝到dest2</td>
    </tr>
    <tr>
        <td>3</td> <td>partition_point(beg, end, unaryPred)</td> <td>输入序列必须是已经用unaryPred划分过的</td>
    </tr>
    <tr>
        <td>4</td> <td>stable_partition(beg, end, unaryPred)</td> <td>使用unaryPred划分输入序列，满足unaryPred的元素在前，不满足的在后</td>
    </tr>
    <tr>
        <td>5</td> <td>partition(beg, end, unaryPred)</td> <td></td>
    </tr>
    <tr>
        <th colspan="3">排序算法</th>
    </tr>
    <tr>
        <td>1</td> <td>sort(beg, end) -> bool</td> <td></td>
    </tr>
    <tr>
        <td>2</td> <td>stable_sort(beg, end)</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>sort(beg, end, comp)</td> <td></td>
    </tr>
    <tr>
        <td>4</td> <td>stable_sort(beg, end, comp)</td> <td></td>
    </tr>
    <tr>
        <td>5</td> <td>is_sorted(beg, end) -> bool</td> <td></td>
    </tr>
    <tr>
        <td>6</td> <td>is_sorted(beg, end, comp) -> bool</td> <td></td>
    </tr>
    <tr>
        <td>7</td> <td>is_sorted_until(beg, end) -> iterator</td> <td>在输入序列中找出最长初始有序子序列，并返回子序列的尾后迭代器</td>
    </tr>
    <tr>
        <td>8</td> <td>is_sorted_until(beg, end, comp) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>9</td> <td>partial_sort(beg, mid, end)</td> <td>只排序beg到mid的元素</td>
    </tr>
    <tr>
        <td>10</td> <td>partial_sort(beg, mid, end, comp) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>11</td> <td>partial_sort_copy(beg, end, destBeg, destEnd)</td> <td>只排序(destEnd-destBeg)个元素，并将它们复制到dest</td>
    </tr>
    <tr>
        <td>12</td> <td>partial_sort_copy(beg, end, destBeg, destEnd, comp) -> iterator</td> <td></td>
    </tr>
    <tr>
        <td>13</td> <td>nth_element(beg, nth, end)</td> <td>nth是一个迭代器，指向输入序列中的一个元素。nth之前的元素都<=它，之后的元素>=它</td>
    </tr>
    <tr>
        <td>14</td> <td>nth_element(beg, nth, end, comp)</td> <td></td>
    </tr>
</table>

### A.2.6 通用重排算法
<table>
    <tr>
        <th colspan="3">使用前向迭代器的重排算法</th>
    </tr>
    <tr>
        <td>1</td> <td>remove(beg, end, val)</td> <td></td>
    </tr>
    <tr>
        <td>2</td> <td>remove_if(beg, end, unaryPred)</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>remove_copy(beg, end, dest, val)</td> <td></td>
    </tr>
    <tr>
        <td>4</td> <td>remove_copy_if(beg, end, dest, unaryPred)</td> <td></td>
    </tr>
    <tr>
        <td>5</td> <td>unique(beg, end)</td> <td>去除相邻的重复元素</td>
    </tr>
    <tr>
        <td>6</td> <td>unique(beg, end, binaryPred)</td> <td></td>
    </tr>
    <tr>
        <td>7</td> <td>unique_copy(beg, end, dest)</td> <td></td>
    </tr>
    <tr>
        <td>8</td> <td>unique_copy_if(beg, end, dest, binaryPred)</td> <td></td>
    </tr>
    <tr>
        <td>9</td> <td>rotate(beg, mid, end)</td> <td>元素mid成为首元素，随后是mid+1到end之前的元素，再接着是beg到mid之前的元素</td>
    </tr>
    <tr>
        <td>10</td> <td>rotate_copy(beg, mid, end, dest) -> iterator</td> <td></td>
    </tr>
    <tr>
        <th colspan="3">使用双向迭代器的重排算法</th>
    </tr>
    <tr>
        <td>1</td> <td>reverse(beg, end)</td> <td>翻转序列中的元素</td>
    </tr>
    <tr>
        <td>2</td> <td>reverse_copy(beg, end, dest)</td> <td></td>
    </tr>
    <tr>
        <th colspan="3">使用随机访问迭代器的重排算法</th>
    </tr>
    <tr>
        <td>1</td> <td>random_shuffle(beg, end)</td> <td>混洗输入序列中的元素</td>
    </tr>
    <tr>
        <td>2</td> <td>random_shuffle(beg, end, rand)</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>shuffle(beg, end, Uniform_rand)</td> <td></td>
    </tr>
</table>

### A.2.7 排列算法
<table>
    <tr>
        <td>1</td> <td>is_permutation(beg1, end1, beg2)</td> <td></td>
    </tr>
    <tr>
        <td>2</td> <td>is_permutation(beg1, end1, beg2, binaryPred)</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>next_permutation(beg, end)</td> <td></td>
    </tr>
    <tr>
        <td>4</td> <td>next_permutation(beg, end, comp)</td> <td></td>
    </tr>
    <tr>
        <td>5</td> <td>prev_permutation(beg, end)</td> <td></td>
    </tr>
    <tr>
        <td>6</td> <td>prev_permutation(beg, end, comp)</td> <td></td>
    </tr>
</table>

### A.2.8 有序序列的集合算法
<table>
    <tr>
        <td>1</td> <td>includes(beg, end, beg2, end2)</td> <td>如果第2个序列中的每个元素都包含在第1个序列中，则返回true；否则返回false</td>
    </tr>
    <tr>
        <td>2</td> <td>includes(beg, end, beg2, end2, comp)</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>set_union(beg, end, beg2, end2, dest)</td> <td>把2个序列的并集输出到dest中</td>
    </tr>
    <tr>
        <td>4</td> <td>set_union(beg, end, beg2, end2, dest, comp)</td> <td></td>
    </tr>
    <tr>
        <td>5</td> <td>set_intersection(beg, end, beg2, end2, dest)</td> <td>把2个序列的交集输出到dest中</td>
    </tr>
    <tr>
        <td>6</td> <td>set_intersection(beg, end, beg2, end2, dest, comp)</td> <td></td>
    </tr>
    <tr>
        <td>7</td> <td>set_difference(beg, end, beg2, end2, dest)</td> <td>把出现在第一个序列，但第二个序列中没有的元素输出到dest中</td>
    </tr>
    <tr>
        <td>8</td> <td>set_difference(beg, end, beg2, end2, dest, comp)</td> <td></td>
    </tr>
    <tr>
        <td>9</td> <td>set_symmetric_difference(beg, end, beg2, end2, dest)</td> <td>把只出现在第1个序列不出现第2个序列中的元素输出到dest中</td>
    </tr>
    <tr>
        <td>10</td> <td>set_symmetric_difference(beg, end, beg2, end2, dest, comp)</td> <td></td>
    </tr>
</table>

### A.2.9 最小值和最大值
<table>
    <tr>
        <th colspan="3">比较算法</th>
    </tr>
    <tr>
        <td>1</td> <td>min(val1, val2)</td> <td>返回二者较小值</td>
    </tr>
    <tr>
        <td>2</td> <td>min(val1, val2, comp)</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>min(init_list)</td> <td></td>
    </tr>
    <tr>
        <td>4</td> <td>min(init_list, comp)</td> <td></td>
    </tr>
    <tr>
        <td>5</td> <td>max(val1, val2)</td> <td></td>
    </tr>
    <tr>
        <td>6</td> <td>max(val1, val2, comp)</td> <td></td>
    </tr>
    <tr>
        <td>7</td> <td>max(init_list)</td> <td></td>
    </tr>
    <tr>
        <td>8</td> <td>max(init_list, comp)</td> <td></td>
    </tr>
    <tr>
        <td>9</td> <td>minmax(val1, val2)</td> <td></td>
    </tr>
    <tr>
        <td>10</td> <td>minmax(val1, val2, comp)</td> <td></td>
    </tr>
    <tr>
        <td>11</td> <td>minmax(init_list)</td> <td></td>
    </tr>
    <tr>
        <td>12</td> <td>minmax(init_list, comp)</td> <td></td>
    </tr>
    <tr>
        <td>13</td> <td>min_element(beg, end)</td> <td></td>
    </tr>
    <tr>
        <td>14</td> <td>min_element(beg, end, comp)</td> <td></td>
    </tr>
    <tr>
        <td>15</td> <td>max_element(beg, end)</td> <td></td>
    </tr>
    <tr>
        <td>16</td> <td>max_element(beg, end, comp)</td> <td></td>
    </tr>
    <tr>
        <td>17</td> <td>minmax_element(beg, end)</td> <td></td>
    </tr>
    <tr>
        <td>18</td> <td>minmax_element(beg, end, comp)</td> <td></td>
    </tr>
    <tr>
        <th colspan="3">字典序比较</th>
    </tr>
    <tr>
        <td>1</td> <td>lexicographical_compare(beg1, end1, beg2, end2)</td> <td>如果第1个序列在字典序中小于第2个序列，则返回true；否则返回false</td>
    </tr>
    <tr>
        <td>2</td> <td>lexicographical_compare(beg1, end1, beg2, end2, comp)</td> <td></td>
    </tr>
</table>

### A.2.10 数值算法
<table>
    <tr>
        <td>1</td> <td>accumulate(beg, end, init)</td> <td>使用+运算符</td>
    </tr>
    <tr>
        <td>2</td> <td>accumulate(beg, end, init, binaryOp)</td> <td></td>
    </tr>
    <tr>
        <td>3</td> <td>inner_product(beg1, end1, beg2, init)</td> <td>计算2个序列的内积</td>
    </tr>
    <tr>
        <td>4</td> <td>inner_product(beg1, end1, beg2, init, binOp1, binOp2)</td> <td>先执行binOp2，再执行binOp1</td>
    </tr>
    <tr>
        <td>5</td> <td>partial_sum(beg, end, dest)</td> <td>累加</td>
    </tr>
    <tr>
        <td>6</td> <td>partial_sum(beg, end, dest, binaryOp)</td> <td></td>
    </tr>
    <tr>
        <td>7</td> <td>adjacent_difference(beg, end, dest)</td> <td>相邻元素之差，查了第1个元素</td>
    </tr>
    <tr>
        <td>8</td> <td>adjacent_difference(beg, end, dest, binaryOp)</td> <td></td>
    </tr>
    <tr>
        <td>9</td> <td>iota(beg, end, val)</td> <td>将val、val+1、val+2...赋值给beg到end</td>
    </tr>
</table>


