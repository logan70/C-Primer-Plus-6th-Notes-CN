const fs = require('fs')
const path = require('path')

const {
  chapterCNNameMap,
  HEADER,
  exampleDirName,
  exerciseDirName,
  reviewQuestionsDirName,
} = require('./constant')

const {
  resolve,
  getChapterDirs,
  genLink,
} = require('./utils')

main()

function main() {
  const chapterDirs = getChapterDirs()
  const contentStr = chapterDirs.reduce((str, chapter) => {
    str += getTitle(chapter)
    str += getNoteLink(chapter)
    str += getReviewQuestionsLink(chapter)
    str += getExerciseLinks(chapter)
    return str
  }, '')
  const readmeStr = HEADER + contentStr
  fs.writeFileSync(resolve('README.md'), readmeStr, 'utf-8')
}

function getTitle(chapter) {
  return `## ${chapterCNNameMap[chapter]}\n\n`
}

function getNoteLink(chapter) {
  const noteFile = resolve(chapter, 'README.md')
  if (!fs.existsSync(noteFile)) return ''
  return `[【学习笔记】](${genLink(chapter)})\n\n`
}

function getReviewQuestionsLink(chapter) {
  const reviewQuestionsFile = resolve(chapter, reviewQuestionsDirName, 'Answers.md')
  if (!fs.existsSync(reviewQuestionsFile)) return ''
  return `[【复习题解析】](${genLink(reviewQuestionsFile)})\n\n`
}

function getExerciseLinks(chapter) {
  const exerciseDir = resolve(chapter, exerciseDirName)
  if (!fs.existsSync(exerciseDir)) return ''
  const exerciseFiles = fs.readdirSync(exerciseDir).filter(file => path.extname(file) === '.c')
  if (!exerciseFiles || !exerciseFiles.length) return ''

  const title = `[【编程练习】](${genLink(exerciseDir)})\n`
  const content = exerciseFiles
    .map(file => `[${file.slice(0, -2)}](${genLink(exerciseDir, file)})`)
    .join(' | \n')
  return title + content + '\n'
}
