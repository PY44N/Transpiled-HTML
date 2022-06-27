const fs = require("fs");
const transpiler = require("./transpiler");
const parser = require("./parser");

let parsed = parser(fs.readFileSync("./in.thtml", "utf8"));

let html = transpiler(parsed);

fs.writeFileSync("out.html", html);
