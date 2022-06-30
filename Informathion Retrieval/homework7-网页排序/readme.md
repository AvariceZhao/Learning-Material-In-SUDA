# `网页排序`

---

本程序利用改写后的倒排索引生成索引字典及|di|模长字典，支持输入已分词或未分词的语句进行查询，查询结果基于网页排序的向量空间模型显示并输出到与查询语句同名的文件中（查询词用#进行标注），查询结果文件输出到`TestExamlple文件夹中`。

### 附件说明

---

- `InvertedIndex.py`为生成新索引文件的源程序
- `WebRank.py`为本次作业主程序
- `Inverted Index`文件夹用于存储倒排索引文件
- `stopwords`文件夹用于存储停语词的词典，运行InvertedIndex.py需要使用
- `data-1k`文件夹存储了若干已提取正文的网页文件，用于输出相关查询语句



### 测试环境：

---

Windows 10 x64

Python 3.10.0



### 运行说明:

---

1.运行`WebRank.py`前确保`./Dict/`目录下存在名为`dict.txt.big.txt`的字典文件，用于对语句进行分词。

2.运行`WebRank.py`前确保`./data-1k/`目录下存在若干已提取正文的网页文本文件,用于输出符合查询结果的相关语句。

3.运行`WebRank.py`前确保`./Inverted Index/`目录下存在名为`Inverted Index.txt`的倒排索引文件，用于生成`|di|`字典和倒排字典。

4.运行`WebRank.py`前确保`./`目录下存在`TestExample`文件夹用于输出查询结果。

---

1.运行`Inverted Index.py`前确保`./data-1k/`目录下存在若干已提取正文的网页文本文件,用于分词并生成新的倒排索引。

2运行`Inverted Index.py`前确保`./Dict/`目录下存在名为`dict.txt.big.txt`的字典文件，用于对语句进行分词。
3.运行`Inverted Index.py`前确保`./stopwords/`目录下存在若干停语词词典用于分词。