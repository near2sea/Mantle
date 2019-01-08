//
//  MTLParentValueTransformer.m
//  Mantle-Mac
//
//  Created by Syt_ios on 2019/1/8.
//  Copyright © 2019 GitHub. All rights reserved.
//

#import "MTLParentValueTransformer.h"

@interface MTLParentValueTransformer ()
@property (nonatomic, copy, readonly) ParentValueTransformerBlock forward;
@end

@implementation MTLParentValueTransformer
+ (instancetype)transformerUsingForward:(ParentValueTransformerBlock)forward {
	return [[self alloc] initWithForward:forward];
}

- (id)initWithForward:(ParentValueTransformerBlock)forward{
	self = [super init];
	if (self == nil) return nil;
	_forward = [forward copy];
	return self;
}

- (id)transformedWithParent:(id)parentJSON value:(id)value success:(BOOL *)outerSuccess error:(NSError **)outerError
{
	NSError *error = nil;
	BOOL success = YES;
	
	id transformedValue = self.forward(parentJSON, value, &success, &error);
	
	if (outerSuccess != NULL) *outerSuccess = success;
	if (outerError != NULL) *outerError = error;
	
	return transformedValue;
}
@end
