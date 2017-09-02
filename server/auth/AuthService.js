const AuthService = (req, res) => {
  const auth = () => {
    res.send({
      status: 200,
    });
  };

  const signUp = () => {
    res.send({
      status: 309,
    });
  };

  return {
    auth,
    signUp,
  };
};

export default AuthService;

