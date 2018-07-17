/*!
 
 @header MGVideoAttributeModel.h
 
 @abstract MGVideo
 
 
 */
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
/*!
 @class
 @abstract 视频属性Model
 */
@interface MGVideoAttributeModel : NSObject

/*!
 @property
 @abstract 视频vid，必填
 */
@property (nonatomic, strong) NSString *vid;

/*!
 @property
 @abstract 视频标题，非必填
 */
@property (nonatomic, strong) NSString *title;

/*!
 @property
 @abstract 视频分类，非必填
 */
@property (nonatomic, strong) NSString *catalog_id;

/*!
 @property
 @abstract 视频分类名称，非必填
 */
@property (nonatomic, strong) NSString *catalog_name;

/*!
 @property
 @abstract 标签列表，多个以英文逗号隔开，非必填
 */
@property (nonatomic, strong) NSString *tags;

/*!
 @property
 @abstract 视频简介，非必填
 */
@property (nonatomic, strong) NSString *summary;

/*!
 @property
 @abstract 视频说明，非必填
 */
@property (nonatomic, strong) NSString *introduction;

/*!
 @property
 @abstract 视频封面，非必填
 */
@property (nonatomic, strong) NSString *cover_img;

@end

/*!
 @class
 @abstract 查询视频属性Model
 */
@interface SearchVideoAdvancedListParams : NSObject

/*!
 @property
 @abstract 视频vid，非必填
 */
@property (nonatomic, strong) NSString *vid;

/*!
 @property
 @abstract 分页大小，非必填 默认10
 */
@property (nonatomic, assign) int page_size;

/*!
 @property
 @abstract 第几页，非必填 默认1
 */
@property (nonatomic, assign) int page_number;

/*!
 @property
 @abstract 视频标题，非必填
 */
@property (nonatomic, strong) NSString *title;

/*!
 @property
 @abstract 目录ID，非必填 0-所有目录 其他-具体id，只有child为1时生效
 */
@property (nonatomic, strong) NSString *catalog_id;

/*!
 @property
 @abstract 是否包括子目录，非必填 0-只包括当前目录，1-包括当前目录和子目录
 */
@property (nonatomic, strong) NSString *child;

/*!
 @property
 @abstract 标签列表，多个以英文逗号隔开，非必填
 */
@property (nonatomic, strong) NSString *tags;

/*!
 @property
 @abstract 是否上线，非必填 41为上线，42为下线
 */
@property (nonatomic, assign) int public_flag;

/*!
 @property
 @abstract 状态，非必填
 */
@property (nonatomic, assign) int status;

/*!
 @property
 @abstract 开始时间，非必填
 */
@property (nonatomic, strong) NSDate *start_date;

/*!
 @property
 @abstract 结束时间，非必填
 */
@property (nonatomic, strong) NSDate *end_date;

@end

/*!
 @class
 @abstract 查询子用户视频属性Model
 */
@interface UgcListParams : NSObject

/*!
 @property
 @abstract 子用户ID，必填
 */
@property (nonatomic, strong) NSString *userID;

/*!
 @property
 @abstract 分页大小，非必填 默认10
 */
@property (nonatomic, assign) int limit;

/*!
 @property
 @abstract 第几页，非必填 默认0
 */
@property (nonatomic, assign) int start;

/*!
 @property
 @abstract 0按创建时间降序、1:按播放次数降序,默认按视频上传时间降序  非必填
 */
@property (nonatomic, assign) int orderby;

/*!
 @property
 @abstract 视频标签，多个以英文逗号隔开，非必填
 */
@property (nonatomic, strong) NSString *tags;

/*!
 @property
 @abstract 视频名称，名称模糊搜索，非必填
 */
@property (nonatomic, strong) NSString *name;

@end

/*!
 @class
 @abstract 视频上传model
 */
@interface UploadVideoParams : NSObject

/*!
 @property
 @abstract 视频地址，必填
 */
@property (nonatomic, strong) NSString *path;

/*!
 @property
 @abstract 文件名称 必填，必须为完整的文件名称，切带后缀，如migu.mp4
 */
@property (nonatomic, strong) NSString *filename;

/*!
 @property
 @abstract 视频标题 必填
 */
@property (nonatomic, strong) NSString *title;

/*!
 @property
 @abstract 视频是否上线 必填，41上线、42不上线
 */
@property (nonatomic, assign) int public_flag;

/*!
 @property
 @abstract 视频是否转码（必填），0转码、1不转码
 */
@property (nonatomic, assign) int trans_flag;

/*!
 @property
 @abstract 转码模板（必填），“0,1,2,3,4”对应转码模版 id:0-流畅 1-标清 2-高清 3-超清 4-原画质，可自由组合
 */
@property (nonatomic, strong) NSString *trans_version;

/*!
 @property
 @abstract 文件分类ID（必填）
 */
@property (nonatomic, assign) int catalog_id;

/*!
 @property
 @abstract 视频标签（非必填），多标签间用“，”连接
 */
@property (nonatomic, strong) NSString *tag;

/*!
 @property
 @abstract 视频描述（非必填），对于视频的描述说明
 */
@property (nonatomic, strong) NSString *desc;

/*!
 @property
 @abstract 需要urlencode，4K长度限制（非必填）
 */
@property (nonatomic, strong) NSString *extension;

/*!
 @property
 @abstract cbFinishUrl 转码回调url（非必填）
 */
@property (nonatomic, strong) NSString *cbFinishUrl;

/*!
 @property
 @abstract cbUploadUrl 上传状态回调地址url（非必填）
 */
@property (nonatomic, strong) NSString *cbUploadUrl;

/*!
 @property
 @abstract cbTransUrl 转码状态回调地址url（非必填）
 */
@property (nonatomic, strong) NSString *cbTransUrl;

/*!
 @property
 @abstract cbReviewUrl 审核状态回调地址url（非必填）
 */
@property (nonatomic, strong) NSString *cbReviewUrl;

/*!
 @property
 @abstract cbCtrlUrl 播控状态回调地址url（非必填）
 */
@property (nonatomic, strong) NSString *cbCtrlUrl;

/*!
 @property
 @abstract 子用户ID（必填）
 */
@property (nonatomic, strong) NSString *gid;

/*!
 @property
 @abstract 封面，非必填
 */
@property (nonatomic, strong) UIImage *image;

/*!
 @property
 @abstract 图片类型，V34、 V23、H32 ，设置封面时有效 非必填
 */
@property (nonatomic, strong) NSString *ugc_type;

@end
