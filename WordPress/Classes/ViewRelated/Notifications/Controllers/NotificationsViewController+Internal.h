#import "NotificationsViewController.h"


@class ABXPromptView;
@class WPTableViewHandler;
@class WPNoResultsView;

@protocol ABXPromptViewDelegate;
@protocol WPTableViewHandlerDelegate;
@protocol SPBucketDelegate;


#pragma mark - Private Properties

@interface NotificationsViewController ()

@property (nonatomic, strong) IBOutlet UIView               *tableHeaderView;
@property (nonatomic, strong) IBOutlet UISegmentedControl   *filtersSegmentedControl;
@property (nonatomic, strong) IBOutlet ABXPromptView        *ratingsView;
@property (nonatomic, strong) IBOutlet NSLayoutConstraint   *ratingsHeightConstraint;
@property (nonatomic, strong) WPTableViewHandler            *tableViewHandler;
@property (nonatomic, strong) WPNoResultsView               *noResultsView;
@property (nonatomic, strong) NSString                      *pushNotificationID;
@property (nonatomic, strong) NSDate                        *pushNotificationDate;
@property (nonatomic, strong) NSDate                        *lastReloadDate;
@property (nonatomic, strong) NSMutableDictionary           *notificationDeletionBlocks;
@property (nonatomic, strong) NSMutableSet                  *notificationIdsBeingDeleted;

- (void)reloadResultsController;

- (void)cancelDeletionForNoteWithID:(NSManagedObjectID *)noteObjectID;
- (BOOL)isNoteMarkedForDeletion:(NSManagedObjectID *)noteObjectID;

@end
