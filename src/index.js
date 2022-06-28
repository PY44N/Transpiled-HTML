const fs = require("fs");
const transpiler = require("./transpiler");
const parser = require("./parser");
const alias = require("./alias");

let parsed = parser(`html([${fs.readFileSync("./in.thtml", "utf8")}])`);

let aliased = alias(parsed);

let html = transpiler(aliased);

fs.writeFileSync("out.html", html);
