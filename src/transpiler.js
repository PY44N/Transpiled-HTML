function compile(ast) {
  let html = "";

  for (let element of ast) {
    if (element.tag == "null") {
      html += compile(element.children);
      continue;
    }
    let props = "";
    for (const [i, v] of Object.entries(element.properties)) {
      props += ` ${i}="${v}"`;
    }
    html += `<${element.tag}${props}>${element.text || ""}${compile(
      element.children
    )}</${element.tag}>`;
  }

  return html;
}

module.exports = function (ast) {
  return compile(ast);
};
