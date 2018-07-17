/*!
 
 @header MiguCloud.h
 
 @abstract MGVideo
 
 @author jiajiguang
 
 */
#import <Foundation/Foundation.h>
#import "MGVideoAttributeModel.h"
#import <UIKit/UIKit.h>
/*!
 @class
 @abstract 咪咕请求类，包括获取视频列表、播放地址，请求均为同步
 */
@interface MiguCloud : NSObject

/*!
 @method
 @abstract 初始化sdk
 @param uid 对应开发者账户ID
 @param atoken 对应开发者账户atoken
 @param ftoken 对应开发者账户ftoken
 */
+ (void)initSdkWithUid:(NSString *)uid atoken:(NSString *)atoken ftoken:(NSString *)ftoken;

/*!
 @method
 @abstract 获取点播列表
 @param params 视频属性
 @result 返回结果
 */
+ (NSDictionary *)getMediaList:(SearchVideoAdvancedListParams *)params;


/*!
 @method
 @abstract 获取某一点播视频的视频地址(无防盗链)
 @param vid 视频ID（必填）
 @param vtype 模板IDlist（非必填）多个模板以","间隔，如:0,1,2参照
 @param source 源站标识（非必填）字段不传时默认走cdn,source=www.migucloud.com 时走源站播放
 @result 返回结果
 */
+ (NSDictionary *)getMediaUrl:(NSString *)vid vtype:(NSString *)vtype source:(NSString *)source;

/*!
 @method
 @abstract 获取某一点播视频的视频地址(防盗链)
 @param vid 视频ID（必填）
 @param vtype 码率类型（非必填）模板IDlist,多个模板以","间隔，如:0,1,2
 @result 返回结果
 */
+ (NSDictionary *)getMediaUrlVerify:(NSString *)vid vtype:(NSString *)vtype;

/*!
 @method
 @abstract 获取子用户视频列表
 @param params 属性
 @result 返回结果
 */
+ (NSDictionary *)getMediaUserList:(UgcListParams *)params;

/*!
 @method
 @abstract 获取视频下载地址
 @param vid 视频vid
 @result 返回结果
 */
+ (NSDictionary *)getMediaDownloadUrl:(NSString *)vid;

/*!
 @method
 @abstract 获取视频下载地址
 @param vids 视频vid，多个vid用英文 ","隔开，最多20个
 @result 返回结果
 */
+ (NSDictionary *)getMediaDownloadUrlList:(NSString *)vids;

/*!
 @method
 @abstract 删除视频，支持同时删除多个
 @param vid 视频对应的唯一标识
 @param userID 子用户唯一标识
 @result 返回结果
 */
+ (NSDictionary *)deleteMedia:(NSString *)vid userID:(NSString *)userID;

/*!
 @method
 @abstract 删除视频
 @param vid 视频对应的唯一标识
 @result 返回结果
 */
+ (NSDictionary *)deleteMedia:(NSString *)vid;

/*!
 @method
 @abstract 修改视频信息
 @param videoModel 视频model
 @result 返回结果
 */
+ (NSDictionary *)modifyMedie:(MGVideoAttributeModel *)videoModel;

@end
