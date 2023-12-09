
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
	- Add stats on render time
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
- Refactor
	- [x] Relabel Julia as Point
	- [ ] Clean up Aux Code
		- [x] Rename some functions (point -> pointSet)
		- [x] Delete unused functions
		- Migrate to SetImage


### Priority:

- [x] Timing
- [x] Refactoring
	- [x] Display box class
- 


### Working


To start off today I'd like to do some refactoring:

- [x] Convert Point calc to function
- [x] Minor formatting
	- [ ] Add alpha to the status colours
- [x] Try to implement subclasses
	- Succeeded for LCDPanel groupbox
- [ ] Image docking

For features:

- [x] Flesh out timing display
	- [x] Image update
	- [x] Set calculation
	- [x] Bitmap generation
- [ ] Controls
	- [ ] Colour palette
		- [ ] Select
		- [ ] Parameters
	- [ ] Image
		- [ ] Undock images for easier scaling
- [ ] Resource Usage
	- [ ] CPU
		- [ ] Display
		- [ ] Set max
	- [ ] Memory
		- [ ] Display
		- [ ] Set max


Image docking

- Implement dock widget
- Assert aspect ratio
	- Subclass QLabel
- Update control functions
	- Mouse input needs to be from label coords