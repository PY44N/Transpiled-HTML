const Readstream = require("./stream");

function parse(stream) {
  let ast = [];

  let element = {
    tag: null,
    properties: {},
    children: [],
    text: null,
  };

  element.tag = stream.readUntil(["("]);
  stream.read(); // (

  while (stream.nextChar() != ")") {
    if (stream.nextChar() != "[") {
      let propName = stream.readUntil(["=", ",", ")"]);
      if (stream.nextChar() == "=") {
        stream.read(); // =
        let propValue = stream.readUntil([",", ")"]);
        if (stream.nextChar() == ",") stream.read();

        element.properties[propName] = propValue;
      } else {
        if (stream.nextChar() == ",") stream.read();
        element.text = propName.slice(1, -1);
      }
    } else {
      stream.read(); // [
      while (stream.nextChar() != "]") {
        let elements = parse(stream);

        for (let v of elements) {
          element.children.push(v);
        }
      }
      stream.read(); // ]
    }
  }
  stream.read(); // )

  console.log(element);

  ast.push(element);
  return ast;
}

module.exports = function (code) {
  let stream = new Readstream(code);
  return parse(stream);
};
