BitcoinWallet
=============

A Pebble watch face that displays an image of your Bitcoin (or other alt coin) wallet's QR code. 

In resources/images/ there is a .png file called "wallet.png". To adapt this watch face for your own purposes, all you need to do is replace the "wallet.png" with a PNG of your own image, scaled to 140x140 pixels. From there, run:

$ pebble build

$ pebble install --phone "IP ADDRESS OF YOUR PHONE"
