
## ToDo:
- [x] Migrate calc from imageviewer constructor
- [x] Add parallel pragma
	- [x] Add compiler flags
- [x] Time image update
- [x] Time image render
- [x] Change to center & span format
- [x] Update to avoid complex<double> (8x speedup)
	- [x] Mandelbrot
		- [x] Loop K then C, pragma simd on C
	- [x] Julia
- Display
	- Fix resizing of number fields
	- [x] Add stats on render time
	- Add stats on mem usage
- Controls
	- Zoom
		- Button
		- [x] Scroll
	- Pan
	- [x] Recenter
- Features
	- Colour select
	- Function select
		- exp(z^n)
- Documentation
- Error handling
	- [ ] Input boxes
- Refactor
	- [x] Relabel Julia as Point
	- [ ] Clean up Aux Code
		- Migrate to SetImage


### Priority:

- [ ] Dock images
- [ ] Colour control
- [ ] Refactoring
	- [ ] Subclass
		- [x] LineEdit
		- [ ] Input
			- Need to set size policy to avoid resizing everything
		- [ ] Point Set

### Working


To start off today I'd like to do some refactoring:

- [x] Convert Point calc to function
- [x] Minor formatting
	- [ ] Add alpha to the status colours
- [ ] Try to implement subclasses
	- 
- [ ] Image docking

For features:

- [ ] Controls
	- [ ] Colour palette
		- [ ] Select
		- [ ] Parameters
	- [ ] Image
		- [ ] Undock images for easier scaling
- [ ] Resource Usage
	- [ ] CPU
		- [ ] Display
		- [ ] Set max cores
	- [ ] Memory
		- [ ] Display
		- [ ] Set max RAM


Image docking

- Implement dock widget
- Assert aspect ratio
	- Subclass QLabel
- Update control functions
	- Mouse input needs to be from label coords

Subclass SetImage
- create basic class
- function

SetImage update:
	- add linkLCD
	- add InputPanel
		- Vector is appropriate (all fields will be checked in sequence)