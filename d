import React from "react";
import { BrowserRouter as Router, Routes, Route, Link } from "react-router-dom";
import Home from "./Home";
import About from "./About";
import Contact from "./Contact";

function App() {
  return (
    <Router>
      <div style={{ fontFamily: "system-ui", padding: 20 }}>
        <h2>React Router Example</h2>
        <nav style={{ marginBottom: 20 }}>
          <Link to="/" style={{ marginRight: 10 }}>Home</Link>
          <Link to="/about" style={{ marginRight: 10 }}>About</Link>
          <Link to="/contact">Contact</Link>
        </nav>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/about" element={<About />} />
          <Route path="/contact" element={<Contact />} />
        </Routes>
      </div>
    </Router>
  );
}

export default App;


import React from "react";

function Home() {
  return <h3>Welcome to the Home Page</h3>;
}

export default Home;


import React from "react";

function About() {
  return <h3>This is the About Page</h3>;
}

export default About;


import React from "react";

function Contact() {
  return <h3>Contact us at contact@example.com</h3>;
}

export default Contact;





1.npx create-react-app myrouterapp
2.cd myrouterapp
3.npm install react-router-dom
4.code .
5.npm start