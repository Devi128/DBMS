const express = require('express');
const app = express();
const port = 3000;

app.use(express.json());

app.get('/', (req, res) => {
  res.send('Welcome to the Express.js example!');
});

app.get('/users/:id', (req, res) => {
  const userId = req.params.id;
  res.send(`User ID received: ${userId}`);
});

app.get('/search', (req, res) => {
  const query = req.query.q;
  const page = req.query.page || 1;
  res.send(`Search query: ${query}, Page: ${page}`);
});

app.post('/users', (req, res) => {
  const name = req.body.name;
  res.status(201).send(`User '${name}' created successfully!`);
});

app.get('/info', (req, res) => {
  const fullUrl = `${req.protocol}://${req.get('host')}${req.originalUrl}`;
  res.send(`Full URL of this request: ${fullUrl}`);
});

app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
});