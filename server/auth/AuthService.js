import bcrypt from 'bcrypt';
import FileWrapper from './../helpers/file-wrapper';
import DateHelper from './../helpers/date';

const fileManager = FileWrapper('./auth');

const AuthService = (req, res) => {
  const fileName = 'users.mock.json';

  const auth = () => {
    res.send({
      status: 200,
    });
  };

  const signUp = () => {
    let users = [];
    fileManager.readFile(fileName, (err, data) => {
      if (err) {
        res.send({
          message: 'Problem with the register',
        });
        return;
      }
      const usersSaved = data.length === 0 ? [] : JSON.parse(data);

      const expirationDate = DateHelper.getNextDay();
      const token = Math.random().toString(36).slice(10);

      const body = {
        ...req.body,
        password: bcrypt.hashSync(req.body.password, 10),
        token,
        expirationDate,
      };

      users = [...usersSaved, body];

      fileManager.writeFile(fileName, users, (errWriting) => {
        if (errWriting) {
          res.send({
            message: 'Problem with the register',
          });
          return;
        }

        res.send({
          token,
          expirationDate,
        });
      });
    });
  };

  return {
    auth,
    signUp,
  };
};

export default AuthService;

