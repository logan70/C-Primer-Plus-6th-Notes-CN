/**
 * Do some preparatory works for learning next chapter.
 */
const fs = require('fs')
const {
  chapterCNNameMap,
  allChapters,
  exampleDirName,
  exerciseDirName,
  imagesDirName,
  reviewQuestionsDirName,
  reviewQuestionsFileName,
} = require('./constant')
const {
  getChapterDirs,
  resolve,
} = require('./utils')
 
main()

function main() {
  const chaptersAlreadyLearned = getChapterDirs()
  const chaptersNotLearned = allChapters.filter(chapter => !chaptersAlreadyLearned.includes(chapter))
  const nextChapter = chaptersNotLearned[0]
  fs.mkdirSync(resolve(nextChapter)) // make root dir of next chapter
  fs.mkdirSync(resolve(nextChapter, exampleDirName)) // make example dir of next chapter
  fs.mkdirSync(resolve(nextChapter, exerciseDirName)) // make programming-exercise dir of next chapter
  fs.mkdirSync(resolve(nextChapter, imagesDirName)) // make images dir of next chapter
  fs.mkdirSync(resolve(nextChapter, reviewQuestionsDirName)) // make review-questions dir of next chapter
  fs.writeFileSync(resolve(nextChapter, reviewQuestionsDirName, reviewQuestionsFileName), '') // make review-questions file of next chapter
  fs.writeFileSync(resolve(nextChapter, 'README.md'), `# ${chapterCNNameMap[nextChapter]}\n\n`)// generate READMD.md
}
