//
//  JTProximitySDK.h
//  JTProximitySDK
//
//  Created by Michele Ambrosi on 06/07/17.
//  Copyright © 2017 Jointag Srl. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 100000

#import <UserNotifications/UserNotifications.h>

#endif
typedef NS_ENUM(NSInteger, JTPLogLevel) {
    JTPLogLevelVerbose,
    JTPLogLevelDebug,
    JTPLogLevelInfo,
    JTPLogLevelWarn,
    JTPLogLevelError
};
extern NSString *const SDK_VERSION;
extern NSInteger const SDK_BUILD;

@protocol JTProximityCustomDelegate<NSObject>

- (void)jtProximityDidReceiveCustomAction:(NSString *)customAction;

@end

NS_SWIFT_NAME(ProximitySDK)
@interface JTProximitySDK : NSObject

@property (readonly, nonatomic) NSString *apiKey;

@property (readonly, nonatomic) NSString *apiSecret;

@property (readonly, nonatomic) BOOL debug;

@property (assign, nonatomic) BOOL promptForPushNotifications;

@property (assign, nonatomic) BOOL promptForLocationAuthorization;

@property (weak, nonatomic) id<JTProximityCustomDelegate> customDelegate;

+ (instancetype)sharedInstance NS_SWIFT_NAME(instance());

- (void)setLogLevel:(JTPLogLevel)logLevel;

- (void)initWithLaunchOptions:(NSDictionary *)launchOptions apiKey:(NSString *)apiKey apiSecret:(NSString *)apiSecret;

- (void)initWithLaunchOptions:(NSDictionary *)launchOptions apiKey:(NSString *)apiKey apiSecret:(NSString *)apiSecret debug:(BOOL)debug;

// Pre iOS 10
- (BOOL)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification;

// iOS 10 only
- (BOOL)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification __IOS_AVAILABLE(10.0);

- (BOOL)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response __IOS_AVAILABLE(10.0);

- (nonnull NSString *)installationId;

- (nullable NSString *)advertisingId;

- (void)requestLocationAuthorization;

@end
