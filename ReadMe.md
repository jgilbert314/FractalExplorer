
imageviewer:
- primarily for UI interface

setimage:
- Manages image sets (display, update, relevant IO)

AuxiliaryCode:
- Original function implementation. Mostly deprecated now

Controls: 
- If you happen to be able to run this:
	- Shift-Click images to recenter in that area
	- Shift-Scroll to zoom in and out
	- Ctrl-MouseMove inside the Mandelbrot set to continuously 
	  update the Julia set (use constant at mouse position to generate Julia set)
	- Use text boxes to update parameters directly
- Parameters
	- Center: 
		- Ro: real component of origin (horizontal pan)
		- Io: imag component of origin (vertical pan)
	- Scale: 
		- Rs: span of real axis (horizontal)
		- Is: span of imag axis (vertical)
		- Recommend keeping these equal
	- Resolution:
		- N_R: horizontal resolution
		- N_I: vertical resolution
		- Recommended: 
			- keeping these equal
			- Low-res = 100
			- Detail = 250-500
			- High def = 1000
		- Note:
			- Memory/time cost scale like N_R\*N_I
	- Julia Set:
		- cR, cI:
			- Components of the constant used to produce the Julia set
			- Select these from the Mandelbrot set -- local features of Mandelbrot set influence Julia set
	- N_K
		- Number of iterations in computation
		- Increasing increases detail, but shrinks feature size
		- Works best to increase this as you zoom
		- Recommended:
			- Fast   = 100-250
			- Detail = 500
			- Extreme detail = 1000
		- Note:
			- Computation time scales linearly with N_K
