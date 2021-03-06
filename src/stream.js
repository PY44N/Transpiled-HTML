class Readstream {
  constructor(str) {
    this.text = str
      .replace(/\s+(?=([^"]*"[^"]*")*[^"]*$)/g, "")
      .replace(/\r/g, "")
      .replace(/\n/g, "");
    this.pos = 0;
    this.atEnd = false;
  }

  read(count = 1) {
    let ret = this.text.substring(this.pos, this.pos + count);
    this.pos += count;
    this.atEnd = this.pos == this.text.length;
    return ret;
  }

  readUntil(char) {
    let ret = "";

    while (!char.includes(this.text[this.pos])) {
      ret += this.read();
    }

    return ret;
  }

  nextChar() {
    return this.text[this.pos];
  }

  assertRead(chars) {
    let text = this.read();
    if (!chars.includes(text)) {
      throw new Error(
        `Invalid char, expected: ${chars.join(" or ")} got: ${text}`
      );
    }
  }
}

module.exports = Readstream;
