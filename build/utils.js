const fs = require('fs')
const path = require('path')

exports.resolve = resolve
exports.genLink = genLink
exports.getChapterDirs = getChapterDirs

function resolve(...pathArr) {
  return path.resolve(rootPath, ...pathArr)
}

/**
 * get file/path link url used in markdown
 * 
 * @param {String} p absolute local path for a path or a file
 * @return {String} link url used by markdown file 
 */
const rootPath = path.resolve(__dirname, '../')
const fileBasePath = 'https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/blob/master/'
const dirBasePath = 'https://github.com/logan70/C-Primer-Plus-6th-Notes-CN/tree/master/'
function genLink(...pathArr) {
  const absolutePath = resolve(...pathArr)
  const relativePath = path.relative(rootPath, absolutePath)
  const ext = path.extname(relativePath)
  if (!ext) {
    return dirBasePath + encodeURI(relativePath)
  }
  const isImage = /jpe?g|png|gif/.test(ext)
  const link = fileBasePath + relativePath + (isImage ? '?raw=true' : '')
  return encodeURI(link)
}

function getChapterDirs() {
  return fs.readdirSync(resolve())
    .filter(name => {
      if (!name.startsWith('Chapter')) return false
      const isDir = fs.statSync(resolve(name)).isDirectory()
      return isDir
    }, [])
}
