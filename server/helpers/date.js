export default {
  getNextDay() {
    const today = new Date();
    return new Date(today.getTime() + (24 * 60 * 60 * 1000));
  },
};
