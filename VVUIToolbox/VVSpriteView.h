
#import <Cocoa/Cocoa.h>
#import "VVSpriteManager.h"
#include <libkern/OSAtomic.h>




extern int				_spriteViewCount;




@interface VVSpriteView : NSView {
	BOOL					deleted;
	VVSpriteManager			*spriteManager;
	BOOL					spritesNeedUpdate;
	
	os_unfair_lock				propertyLock;
	NSEvent					*lastMouseEvent;
	NSColor					*clearColor;
	BOOL					drawBorder;
	NSColor					*borderColor;
	
	long					mouseDownModifierFlags;
	VVSpriteEventType		mouseDownEventType;
	long					modifierFlags;
	BOOL					mouseIsDown;
	__weak NSView			*clickedSubview;	//	NOT RETAINED
}

- (void) generalInit;

- (void) prepareToBeDeleted;

- (void) finishedDrawing;

- (void) updateSprites;

@property (readonly) BOOL deleted;
@property (readonly) VVSpriteManager *spriteManager;
@property (assign, readwrite) BOOL spritesNeedUpdate;
- (void) setSpritesNeedUpdate;
@property (readonly) NSEvent *lastMouseEvent;
@property (strong,readwrite) NSColor *clearColor;
@property (assign,readwrite) BOOL drawBorder;
@property (strong,readwrite) NSColor *borderColor;
@property (readonly) long mouseDownModifierFlags;
@property (assign,readwrite) VVSpriteEventType mouseDownEventType;
@property (readonly) long modifierFlags;
@property (readonly) BOOL mouseIsDown;

@end
