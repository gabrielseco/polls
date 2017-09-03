import fs from 'fs';
import path from 'path';

const FileWrapper = (pathname) => {
  const writeFile = (fileName, data, cb, encoding = 'utf-8') => {
    fs.writeFile(path.join(pathname, fileName), JSON.stringify(data), encoding, (err) => {
      if (err) {
        cb(err);
      }

      cb();
    });
  };

  const readFile = (fileName, cb) => {
    fs.readFile(path.join(pathname, fileName), (err, data) => {
      if (err) {
        cb(err, null);
      }

      cb(null, data);
    });
  };

  return {
    writeFile,
    readFile,
  };
};

export default FileWrapper;
