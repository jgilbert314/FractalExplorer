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
- [x] Refactor
	- [x] Relabel Julia as Point
- Controls
	- Zoom
		- Scroll
			- [x] Map
			- [x] Julia
		- [x] Recenter
			- [x] Map
			- [x] Julia
	- Constant select
		- [x] Mouse click
		- [x] Mouse movement
			- [x] Override mouseMoveEvent
			- [x] Call const getter function
			- [x] Update set
		- Tooltip
- Improvements
	- [ ] Only update set on modification	
		- [ ] Add mod flag
		- [ ] Set flag in parameter updates
		- [ ] Check before update
- Class update


### Working

- General calc
	- Function pointer for set function
	- Pointer to arguments



### Misc
M
R0 0.273173
I0 0.00677681
Rs 0.00250631
Is 0.00250631
N = 250
K = 125

P
R0 0.178795
I0 0.216501
Rs 2.5
Is 2.5
cR 0.273943
cI 0.00686237
N = 1000
K = 500


---

M
Ro 0.358997
Io 0.0942348
Rs 0.012173
Is 0.012173
N 1000
K 1000

P
Ro 0
Io 0
Rs 0.105978
Is 0.105978
cR 0.358967
cI 0.0937413
N 1000
K 1000