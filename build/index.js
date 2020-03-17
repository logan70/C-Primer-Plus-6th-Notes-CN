const fs = require("fs");
const path = require("path");

const {
  chapterCNNameMap,
  HEADER,
  exampleDirName,
  exerciseDirName,
  reviewQuestionsDirName,
  reviewQuestionsFileName,
} = require("./constant");

const {
  resolve,
  getChapterDirs,
  genLink,
  getAllMarkDowns,
} = require("./utils");

function main() {
  generateRootReadme();
  replaceAllLinksInMarkDownFiles();
}

function generateRootReadme() {
  const chapterDirs = getChapterDirs();
  const contentStr = chapterDirs.reduce((str, chapter) => {
    str += getTitle(chapter);
    str += getNoteLink(chapter);
    str += getReviewQuestionsLink(chapter);
    str += getExerciseLinks(chapter);
    return str;
  }, "");
  const readmeStr = HEADER + contentStr;
  const readmePath = resolve('README.md');
  fs.writeFileSync(readmePath, readmeStr, "utf-8");
  replaceLinks(readmePath)
}

function replaceAllLinksInMarkDownFiles() {
  const mdFiles = getAllMarkDowns();
  mdFiles.forEach(file => replaceLinks(file))
}

const genLinkReg = /genLink\(['"]?(.+?)['"]?\)/ig;
function replaceLinks(mdFilePath) {
  if (!fs.existsSync(mdFilePath))
    return console.log(`${mdFilePath} is not exist`);
  
  const mdFileDir = path.resolve(mdFilePath, '..')
  const readmeStr = fs
    .readFileSync(mdFilePath, "utf-8")
    .replace(genLinkReg, (_, imgPath) => genLink(mdFileDir, imgPath));
  fs.writeFileSync(mdFilePath, readmeStr, "utf-8");
}

function getTitle(chapter) {
  return `## ${chapterCNNameMap[chapter]}\n\n`;
}

function getNoteLink(chapter) {
  const noteFile = resolve(chapter, "README.md");
  if (!fs.existsSync(noteFile)) return "";
  return `[【学习笔记】](${genLink(chapter)})\n\n`;
}

function getReviewQuestionsLink(chapter) {
  const reviewQuestionsFile = resolve(
    chapter,
    reviewQuestionsDirName,
    reviewQuestionsFileName
  );
  if (!fs.existsSync(reviewQuestionsFile)) return "";
  return `[【复习题解析】](${genLink(reviewQuestionsFile)})\n\n`;
}

function getExerciseLinks(chapter) {
  const exerciseDir = resolve(chapter, exerciseDirName);
  if (!fs.existsSync(exerciseDir)) return "";
  const exerciseFiles = fs
    .readdirSync(exerciseDir)
    .filter(file => path.extname(file) === ".c");
  if (!exerciseFiles || !exerciseFiles.length) return "";

  const title = `[【编程练习】](${genLink(exerciseDir)})\n`;
  const content = exerciseFiles
    .map(file => `[${file.slice(0, -2)}](${genLink(exerciseDir, file)})`)
    .join(" | \n");
  return title + content + "\n\n";
}

main();
