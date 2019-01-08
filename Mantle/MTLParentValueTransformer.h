//
//  MTLParentValueTransformer.h
//  Mantle-Mac
//
//  Created by Syt_ios on 2019/1/8.
//  Copyright © 2019 GitHub. All rights reserved.
//

#import <Mantle/Mantle.h>
typedef id (^ParentValueTransformerBlock)(id parentJSON, id value, BOOL *success, NSError **error);

/**
 *	使用例子参考如下：
	 id<MTLTransformerErrorHandling> dictionaryTransformer = [MTLJSONAdapter dictionaryTransformerWithModelClass:[TabInfoBaseModel class]];
 
	 return [SYTValueTransformer transformerUsingForward:^id(NSDictionary *parentJSON, NSArray *dictionaries, BOOL *success, NSError *__autoreleasing *error) {
		 if (dictionaries == nil) return nil;
 
		 NSMutableArray *models = [NSMutableArray arrayWithCapacity:dictionaries.count];
		 for (id JSONDictionary in dictionaries) {
		 if (JSONDictionary == NSNull.null) {
		 [models addObject:NSNull.null];
		 continue;
		 }
 
		 JSONDictionary[@"markType"] = parentJSON[@"type"];
		 id model = [dictionaryTransformer transformedValue:JSONDictionary success:success error:error];
 
		 if (*success == NO) return nil;
 
		 if (model == nil) continue;
 
		 [models addObject:model];
		 }
 
		 return models;
	 }];
 */

@interface MTLParentValueTransformer : MTLValueTransformer
+ (instancetype)transformerUsingForward:(ParentValueTransformerBlock)transformation;
@end

