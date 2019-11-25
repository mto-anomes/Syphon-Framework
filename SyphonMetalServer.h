#import "SyphonServerBase.h"
#import <Metal/MTLPixelFormat.h>
#import <Metal/MTLTexture.h>
#import <Metal/MTLCommandBuffer.h>


NS_ASSUME_NONNULL_BEGIN

#define SYPHON_METAL_SERVER_UNIQUE_CLASS_NAME SYPHON_UNIQUE_CLASS_NAME(SyphonMetalServer)
@interface SYPHON_METAL_SERVER_UNIQUE_CLASS_NAME : SyphonServerBase

- (id)initWithName:(NSString*)name device:(id<MTLDevice>)device colorPixelFormat:(MTLPixelFormat)colorPixelFormat options:(NSDictionary *)options;

// API Method 1
- (void)drawFrame:(void(^)(id<MTLTexture> texture,id<MTLCommandBuffer> commandBuffer))frameHandler size:(NSSize)size commandBuffer:(id<MTLCommandBuffer>)commandBuffer;

// API Method 2
- (void)publishFrameTexture:(id<MTLTexture>)texture imageRegion:(NSRect)region;
- (void)publishFrameTexture:(id<MTLTexture>)texture;


- (id<MTLTexture>)newFrameImage;
- (void)stop;

@end

NS_ASSUME_NONNULL_END
