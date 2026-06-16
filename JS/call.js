const user = {
  firstname: "mukta",
  lastname: "kumari",
};

const fullBio = function (state) {
  console.log(
    "user name " +
      user.firstname +
      "last name" +
      user.lastname +
      "state" +
      state,
  );
};

fullBio.call(user, "delhi");
const user2 = {
  firstname: "krisha",
  lastname: "govinda",
};

fullBio.call(user2, "vrindavan");// how we call this function -> 
fullBio.apply(user, ["barsna"]);

let printMyName = fullBio.bind(user2, "kolkata");
printMyName()

