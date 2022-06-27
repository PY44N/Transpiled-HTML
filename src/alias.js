const fs = require("fs");

const aliases = JSON.parse(fs.readFileSync("./alias.json"));

function alias(ast) {
  for (let i in ast) {
    if (aliases[ast[i].tag]) {
      ast[i].tag = aliases[ast[i].tag];
    }

    ast[i].children = alias(ast[i].children);
  }

  return ast;
}

module.exports = function (ast) {
  return alias(ast);
};
