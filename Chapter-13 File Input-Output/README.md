# 第十三章 文件输入/输出

对于大多数C程序而言，写入文件和读取文件必不可少。为此，绝大对数C实现都提供底层I/O和标准高级I/O。因为ANSIC库考虑到可移植性，包含了标准I/O包，但是未提供底层I/O。

标准I/O包自动创建输入和输出缓冲区以加快数据传输。fopen()函数为标准I/O打开一个文件，并创建一个用于存储文件和缓冲区信息的结构。fopen()函数返回指向该结构的指针，其他函数可以使用该指针指定待处理的文件。feof()和ferror()函数报告I/O操作失败的原因。

C把输入视为字节流。如果使用fread()函数，C把输入看作是二进制值并将其储存在指定存储位置。如果使用fscanf()、getc()、fgets()或其他相关函数，C则将每个字节看作是字符码。然后fscanf()和scanf()函数尝试把字符码翻译成转换说明指定的其他类型。例如，输入一个值23，%f转换说明会把23翻译成一个浮点值，%d转换说明会把23翻译成一个整数值，%s转换说明则会把23储存为字符串。getc()和fgetc()系列函数把输入作为字符码储存，将其作为单独的字符保存在字符变量中或作为字符串储存在字符数组中。类似地，fwrite()将二进制数据直接放入输出流，而其他输出函数把非字符数据转换成用字符表示后才将其放入输出流。

ANSIC提供两种文件打开模式：二进制和文本。以二进制模式打开文件时，可以逐字节读取文件；以文本模式打开文件时，会把文件内容从文本的系统表示法映射为C表示法。对于UNIX和Linux系统，这两种模式完全相同。

通常，输入函数getc()、fgets()、fscanf()和fread()都从文件开始处按顺序读取文件。然而，fseek()和ftell()函数让程序可以随机访问文件中的任意位置。fgetpos()和fsetpos()把类似的功能扩展至更大的文件。与文本模式相比，二进制模式更容易进行随机访问。