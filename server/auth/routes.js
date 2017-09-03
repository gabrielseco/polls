import AuthService from './AuthService';

const routes = (app) => {
  let authService;
  app.get('/auth', (req, res) => {
    authService = AuthService(req, res);
    authService.auth();
  });

  app.post('/signup', (req, res) => {
    authService = AuthService(req, res);
    authService.signUp();
  });
};

export default routes;

