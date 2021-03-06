//	mousew.hpp

#ifndef MOUSEW_HPP
#define MOUSEW_HPP

#ifndef EVENT_HPP
#include "event.hpp"
#endif

#ifndef MOUSE_HPP
#include "mouse.hpp"
#endif


class MouseWin : public SOL_Mouse
{
 public:
	MouseWin();
	~MouseWin();

	Bool	Exists() const;
	int	GlobalPos(SOL_Point*) const;
	int	GlobalPosSci(SOL_Point*) const;

	void	SetRestrictRect(const SOL_Rect&);
	void	ClearRestrictRect();
	void	SetPos(const SOL_Point&);
	void	Setup(SOL_Cursor&) {}

	void	WinMouseButton(unsigned, const SOL_Point&);

 protected:
	static	SOL_Cursor*	cursor;
	static	Bool			restrictFlag;
	static	Bool			inCage;
};



class MouseWinClr : public SOL_Mouse
{
 public:
	MouseWinClr();
	~MouseWinClr();

	Bool	Exists() const;
	int	GlobalPos(SOL_Point*) const;  
	int	GlobalPosSci(SOL_Point*) const;
	int	GetSwiftInfo(int* z, int* pitch, int* roll, int* yaw) const;

	void	SetRestrictRect(const SOL_Rect&);
	void	ClearRestrictRect();
	void	SetPos(const SOL_Point&);
	void	Setup(SOL_Cursor&); 
	Bool	IsSwift() const; 
//	void	Vibrate(int duration, int on = 1, int off = 1) const;
	void	WinMouseButton(unsigned, const SOL_Point&);
	void	SetPaintFlag()		{paintFlag = True;}

 protected:
	void	InitMouse();
	void	InstallMouseInterrupt();
	void	ReleaseMouseInterrupt();
//	void	SetMouseDriverPos(const SOL_Point&);

	friend	void __loadds __far HndlMouse(int, int, int, int, int, int);

	static	SOL_Cursor*	cursor;
	static	Bool			useMouse;
	static	Bool			isSwift;
	static	SOL_Point	posScale;
	static	short			zaxis;
	static	short			pitch;
	static	short			roll;
	static	short			yaw;
	static	uchar*		stackBuff;
	static	Bool			paintFlag;
};

extern SOL_Mouse* clrMouse;
extern SOL_Mouse* winMouse;

typedef struct {
	short	x;
	short	y;
	short	z;
	short	pitch;
	short	roll;
	short	yaw;
	short	buttons;
}  SWIFT_3DStatus;


const short lButDown = 0x02;
const short lButUp = 0x04;
const short rButDown = 0x08;
const short rButUp = 0x10;
const short cButDown = 0x20;
const short cButUp = 0x40;  
const short cYAxis = 0x800;
const short cPitch = 0x1000;
const short cRoll = 0x2000;
const short cYaw = 0x4000;

const short	butDown =	lButDown | rButDown | cButDown;
const short	butUp = 		lButUp | rButUp | cButUp;
const short	lButton =	lButDown | lButUp;
const short	rButton = 	rButDown | rButUp;
const short	cButton =	cButDown | cButUp;
const short	swiftFunc =	cYAxis | cPitch | cRoll | cYaw;

#endif

