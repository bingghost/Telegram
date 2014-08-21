#import <Foundation/Foundation.h>

#import "TGModernGalleryDefaultHeaderView.h"
#import "TGModernGalleryDefaultFooterView.h"
#import "TGModernGalleryDefaultFooterAccessoryView.h"

@protocol TGModernGalleryItem;

@interface TGModernGalleryModel : NSObject

@property (nonatomic, strong) NSArray *items;

@property (nonatomic, strong, readonly) id<TGModernGalleryItem> focusItem;

@property (nonatomic, copy) void (^itemsUpdated)(id<TGModernGalleryItem>);
@property (nonatomic, copy) void (^focusOnItem)(id<TGModernGalleryItem>);
@property (nonatomic, copy) UIView *(^actionSheetView)();
@property (nonatomic, copy) UIViewController *(^viewControllerForModalPresentation)();
@property (nonatomic, copy) void (^dismiss)(bool);

- (void)_transitionCompleted;
- (void)_replaceItems:(NSArray *)items focusingOnItem:(id<TGModernGalleryItem>)item;
- (void)_focusOnItem:(id<TGModernGalleryItem>)item;

- (UIView<TGModernGalleryDefaultHeaderView> *)createDefaultHeaderView;
- (UIView<TGModernGalleryDefaultFooterView> *)createDefaultFooterView;
- (UIView<TGModernGalleryDefaultFooterAccessoryView> *)createDefaultLeftAccessoryView;
- (UIView<TGModernGalleryDefaultFooterAccessoryView> *)createDefaultRightAccessoryView;

@end