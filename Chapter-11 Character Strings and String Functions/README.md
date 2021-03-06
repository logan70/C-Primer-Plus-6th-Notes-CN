# 第十一章 字符串和字符串函数

C字符串是一系列char类型的字符，以空字符（'\0'）结尾。字符串可以储存在字符数组中。字符串还可以用字符串常量来表示，里面都是字符，括在双引号中（空字符除外）。编译器提供空字符。因此，"joy"被储存为4个字符j、o、y和\0。strlen()函数可以统计字符串的长度，空字符不计算在内。

字符串常量也叫作字符串——字面量，可用于初始化字符数组。为了容纳末尾的空字符，数组大小应该至少比容纳的数组长度多1。也可以用字符串常量初始化指向char的指针。

函数使用指向字符串首字符的指针来表示待处理的字符串。通常，对应的实际参数是数组名、指针变量或用双引号括起来的字符串。无论是哪种情况，传递的都是首字符的地址。一般而言，没必要传递字符串的长度，因为函数可以通过末尾的空字符确定字符串的结束。

fgets()函数获取一行输入，puts()和fputs()函数显示一行输出。它们都是stdio.h头文件中的函数，用于代替已被弃用的gets()。

C库中有多个字符串处理函数。在ANSIC中，这些函数都声明在string.h文件中。C库中还有许多字符处理函数，声明在ctype.h文件中。

给main()函数提供两个合适的形式参数，可以让程序访问命令行参数。第1个参数通常是int类型的argc，其值是命令行的单词数量。第2个参数通常是一个指向数组的指针argv，数组内含指向char的指针。每个指向char的指针都指向一个命令行参数字符串，argv[0]指向命令名称，argv[1]指向第1个命令行参数，以此类推。

atoi()、atol()和atof()函数把字符串形式的数字分别转换成int、long和double类型的数字。strtol()、strtoul()和strtod()函数把字符串形式的数字分别转换成long、unsignedlong和double类型的数字。