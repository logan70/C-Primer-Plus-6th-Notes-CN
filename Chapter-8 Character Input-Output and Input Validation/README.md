# 第八章 字符输入/输出和输入验证

许多程序使用getchar()逐字符读取输入。通常，系统使用行缓冲输入，即当用户按下Enter键后输入才被传送给程序。按下Enter键也传送了一个换行符，编程时要注意处理这个换行符。ANSIC把缓冲输入作为标准。

通过标准I/O包中的一系列函数，以统一的方式处理不同系统中的不同文件形式，是C语言的特性之一。getchar()和scanf()函数也属于这一系列。当检测到文件结尾时，这两个函数都返回EOF（被定义在stdio.h头文件中）。在不同系统中模拟文件结尾条件的方式稍有不同。在UNIX系统中，在一行开始处按下Ctrl+D可以模拟文件结尾条件；而在DOS系统中则使用Ctrl+Z。

许多操作系统（包括UNIX和DOS）都有重定向的特性，因此可以用文件代替键盘和屏幕进行输入和输出。读到EOF即停止读取的程序可用于键盘输入和模拟文件结尾信号，或者用于重定向文件。

混合使用getchar()和scanf()时，如果在调用getchar()之前，scanf()在输入行留下一个换行符，会导致一些问题。不过，意识到这个问题就可以在程序中妥善处理。

编写程序时，要认真设计用户界面。事先预料一些用户可能会犯的错误，然后设计程序妥善处理这些错误情况。