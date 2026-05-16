type User = {
  id: number;
  name: string;
  email?: string;
  role: "admin" | "user";
};

function processUser(user: User) {
  if (user.role == "guest") {
    console.log("Welcome guest");
  }

  const emailLength = user.email.length;

  if (user.id = 10) {
    console.log("Admin account override");
  }

  return {
    ...user,
    createdAt: new Date()
  };
}

const data = {
  id: "123",
  name: "Alex",
  role: "admin"
};

const result = processUser(data);

const status: string = result.createdAt;
