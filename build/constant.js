const path = require('path')
const {
  resolve,
  genLink,
}  = require('./utils')

exports.exampleDirName = 'example'
exports.exerciseDirName = 'exercise'
exports.imagesDirName = 'images'
exports.reviewQuestionsDirName = 'review-questions'

exports.chapterCNNameMap = {
  'Chapter-1 Getting Started': '第一章 初识C语言',
  'Chapter-2 Introducing C': '第二章 C语言概述',
  'Chapter-3 Data and C': '第三章 数据和C',
  'Chapter-4 Character Strings and Formatted Input/Output': '第四章 字符串和格式化输入/输出',
  'Chapter-5 Operators, Expressions, and Statements': '第五章 运算符、表达式和语句',
  'Chapter-6 C Control Statements: Looping': '第六章 C控制语句：循环',
  'Chapter-7 C Control Statements: Branching and Jumps': '第七章 C控制语句：分支和跳转',
  'Chapter-8 Character Input/Output and Input Validation': '第八章 字符输入/输出和输入验证',
  'Chapter-9 Functions': '第九章 函数',
  'Chapter-10 Arrays and Pointers': '第十章 数组和指针',
  'Chapter-11 Character Strings and String Functions': '第十一章 字符串和字符串函数',
  'Chapter-12 Storage Classes, Linkage, and Memory Management': '第十二章 存储类别、链接和内存管理',
  'Chapter-13 File Input/Output': '第十三章 文件输入/输出',
  'Chapter-14 Structures and Other Data Forms': '第十四章 结构和其他数据形式',
  'Chapter-15 Bit Fiddling': '第十五章 位操作',
  'Chapter-16 The C Preprocessor and the C Library': '第十六章 C预处理器和C库',
  'Chapter-17 Advanced Data Representation': '第十七章 高级数据表示',
}

exports.allChapters = Object.keys(exports.chapterCNNameMap)

exports.HEADER = `
# 《C Primer Plus 中文版（第6版）》学习笔记

![Cover](${genLink('cover.jpg')})

`
