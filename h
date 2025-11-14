const { MongoClient } = require("mongodb");

const uri = "mongodb://localhost:27017";
const client = new MongoClient(uri);

async function run() {
  try {
    await client.connect();
    console.log("Connected to local MongoDB");

    const db = client.db("schoolDB");
    const students = db.collection("students");

    await db.createCollection("teachers");
    console.log("'teachers' collection created in 'schoolDB'");

    await students.insertOne({ name: "Alice", grade: "A" });
    console.log("Inserted a document into 'students' collection");

    await db.collection("teachers").drop();
    console.log("'teachers' collection dropped");

    await db.dropDatabase();
    console.log("'schoolDB' database dropped");
  } catch (error) {
    console.error("Error:", error);
  } finally {
    await client.close();
    console.log("Connection closed");
  }
}

run();






node -v
npm -v
npm init -y
npm install mongodb
node filename.js