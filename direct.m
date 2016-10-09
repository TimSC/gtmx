direct	; Enter direct mode
	v "BREAKMSG":(2+4+8) ; Suppress break message, but leave other break messages intact
	w !
	w "GT.M Rock solid, lightning fast",!
	w $zv,!
	b
	q
