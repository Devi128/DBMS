import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: AnimationExample(),
    );
  }
}

class AnimationExample extends StatefulWidget {
  @override
  _AnimationExampleState createState() => _AnimationExampleState();
}

class _AnimationExampleState extends State<AnimationExample>
    with SingleTickerProviderStateMixin {
  bool _fadeVisible = false, _slideVisible = false;
  late AnimationController _controller;
  late Animation<Offset> _slideAnimation;

  @override
  void initState() {
    super.initState();
    _controller = AnimationController(
        vsync: this, duration: Duration(milliseconds: 500));
    _slideAnimation = Tween(begin: Offset(0, 1), end: Offset.zero).animate(
        CurvedAnimation(parent: _controller, curve: Curves.easeInOut));
  }

  void _toggleFade() => setState(() => _fadeVisible = !_fadeVisible);

  void _toggleSlide() {
    setState(() => _slideVisible = !_slideVisible);
    _slideVisible ? _controller.forward() : _controller.reverse();
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  Widget _buildBox(Color color, String text) {
    return Container(
      width: 150,
      height: 100,
      decoration: BoxDecoration(
        color: color,
        borderRadius: BorderRadius.circular(16),
      ),
      child: Center(child: Text(text, style: TextStyle(fontSize: 18))),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Animations: Fade & Slide"),
        backgroundColor: Colors.yellowAccent,
      ),
      body: Padding(
        padding: EdgeInsets.all(20),
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            // Fade Box
            Column(children: [
              ElevatedButton(
                onPressed: _toggleFade,
                child:
                    Text(_fadeVisible ? "Hide Fade Box" : "Show Fade Box"),
                style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.lightGreenAccent),
              ),
              SizedBox(height: 20),
              AnimatedOpacity(
                opacity: _fadeVisible ? 1 : 0,
                duration: Duration(seconds: 1),
                child: _buildBox(Colors.lightGreenAccent, "Fade Box"),
              ),
            ]),

            // Slide Box
            Column(children: [
              ElevatedButton(
                onPressed: _toggleSlide,
                child:
                    Text(_slideVisible ? "Hide Slide Box" : "Show Slide Box"),
                style: ElevatedButton.styleFrom(
                    backgroundColor: Colors.orange[300]),
              ),
              SizedBox(height: 20),
              SlideTransition(
                position: _slideAnimation,
                child: _buildBox(Colors.orange[300]!, "Slide Box"),
              ),
            ]),
          ],
        ),
      ),
    );
  }
}