/*!
 
 @header MiguDownload.h
 
 @abstract MGVideo
 
 @author jiajiguang
 
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/**
 *  视频特效类型
 */
typedef NS_ENUM(NSInteger , MiguDownloadStatus){
    /**
     *  下载出错
     */
    MiguDownloadStatusError,
    /**
     *  取消下载
     */
    MiguDownloadStatusCannel,
    /**
     *  暂停下载
     */
    MiguDownloadStatusPause,
    /**
     *  下载完成
     */
    MiguDownloadStatusComplete,
};
/*!
 @protocol
 @abstract 这个MGDownloadVideo类的一个protocol
 */
@protocol MiguDownloadDelegate

@optional

/*!
 @method
 @abstract 下载代理，进度相关信息返回
 @param downloaded 已经下载的大小
 @param videoBytesSize 视频总大小
 @param videoPath 视频的下载地址
 */
- (void)downloadVideoWithDownloaded:(int64_t)downloaded videoBytesSize:(int64_t)videoBytesSize downloadVideoPath:(NSString *)videoPath;

/*!
 @method
 @abstract 下载代理，状态信息反馈
 @param status 下载状态
 @param downloadData 暂停或出错时数据返回，用于继续下载
 @param videoPath 下载完成时，对应的沙盒路径
 */
- (void)downloadWithStatus:(MiguDownloadStatus)status resumeData:(NSData *)downloadData didFinishPath:(NSString *)videoPath;

@end
/*!
 @class
 @abstract 咪咕短视频下载类，需创建成为单例类
 */
@interface MiguDownload : NSObject
/*!
 @property
 @abstract   代理
 */
@property (nonatomic, weak) id<MiguDownloadDelegate> delegate;
/*!
 @method
 @abstract 获取单例
 @return 对象
 */
+ (id)shadeInstance;

/*!
 @method
 @abstract 下载视频
 @param videoPath 视频对应下载地址
 */
- (void)startDownloadWithPath:(NSString *)videoPath;

/*!
 @method
 @abstract 暂停下载，信息通过代理返回
 */
- (void)pauseDownload;

/*!
 @method
 @abstract 继续下载
 @param downloadData 暂停视频时对应的返回信息
 */
- (void)resumeDownload:(NSData *)downloadData;

/*!
 @method
 @abstract 取消下载，并删除已下载文件，通过代理返回
 */
- (void)cannelDownload;

@end
