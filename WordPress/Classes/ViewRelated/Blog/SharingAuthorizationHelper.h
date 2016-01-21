#import <Foundation/Foundation.h>

@protocol SharingAuthorizationDelegate;
@class PublicizeService;
@class KeyringConnection;
@class PublicizeConnection;
@class Blog;

@interface SharingAuthorizationHelper : NSObject
@property (nonatomic, weak) id<SharingAuthorizationDelegate>delegate;
- (instancetype)initWithViewController:(UIViewController *)viewController blog:(Blog *)blog publicizeService:(PublicizeService *)publicizeService;
- (void)connectPublicizeService;
- (void)reconnectPublicizeConnection:(PublicizeConnection *)publicizeConnection;
@end

@protocol SharingAuthorizationDelegate <NSObject>

@optional

- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper authorizationSucceededForService:(PublicizeService *)service;
- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper authorizationFailedForService:(PublicizeService *)service;
- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper authorizationCanceledForService:(PublicizeService *)service;

- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper willFetchKeyringsForService:(PublicizeService *)service;
- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper didFetchKeyringsForService:(PublicizeService *)service;
- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper keyringFetchFailedForService:(PublicizeService *)service;

- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper willConnectToService:(PublicizeService *)service usingKeyringConnection:(KeyringConnection *)keyringConnection;
- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper didConnectToService:(PublicizeService *)service withPublicizeConnection:(PublicizeConnection *)keyringConnection;

- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper connectionFailedForService:(PublicizeService *)service;
- (void)sharingAuthorizationHelper:(SharingAuthorizationHelper *)helper connectionCanceledForService:(PublicizeService *)service;

@end
