// basically all the requires
const http = require('http');
const express = require("express");
const { Server } = require("socket.io");
const SerialPort = require("serialport");
var serial = require("serialport");
const { stringify } = require('querystring');
// port constants
const COM_PORT = "COM4";
const BAUD_RATE = 9600;
const DATA_BITS = 8;


// port comms creation
const parsers = serial.parsers;
const parser = new parsers.Readline(
   { delimiter:'\r\n'}
);

var port = new SerialPort(COM_PORT,
{
    baudRate: BAUD_RATE,
    dataBits: DATA_BITS,
    parity: 'none',
    stopBits: 1,
    flowControl: false

});
port.pipe(parser);



// server creation
const app = express();
server = http.createServer(app);
app.get('/', (req, res) => {
    res.sendFile(__dirname + '/Controls.html');
  });

// socket comms
const io = new Server(server);

io.on('connection', (socket) => {
  console.log('Hello Mr Stark');
  // this is such a Liam moment chat
  socket.on('disconnect', () => {
    console.log('Bye Liam');
  });

  socket.on('change motor 1', (value) => {port.write('1' + value);});
  socket.on('change motor 2', (value) => {port.write('2' + value);});
  socket.on('change motor 3', (value) => {port.write('3' + value);});
  socket.on('change motor 4', (value) => {port.write('4' + value);});
  socket.on('MASTER motor', (value) => {port.write('5'+value);});

  port.on('data', function(data){
    console.log(data.toString('utf8'));
    });

});










server.listen(3000, () => {
console.log('listening on *:3000');
});

