<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Compatibility](#compatibility)
- [Installation](#installation)
- [Understanding Userdive iOS SDK operation mode](#understanding-userdive-ios-sdk-operation-mode)
  - [Developer mode](#developer-mode)
  - [Tracking mode](#tracking-mode)
- [Integrate with your app](#integrate-with-your-app)
  - [Preparing integration](#preparing-integration)
    - [Check your Team ID](#check-your-team-id)
    - [Check your Bundle ID](#check-your-bundle-id)
  - [Capturing image](#capturing-image)
    - [Capture images when it detects view transitions](#capture-images-when-it-detects-view-transitions)
    - [Capture images manually](#capture-images-manually)
  - [Tracking gestures](#tracking-gestures)
    - [Automatically detect view transitions](#automatically-detect-view-transitions)
    - [Manually view transitions](#manually-view-transitions)
  - [Using custom parameters](#using-custom-parameters)
  - [Using custom screen name](#using-custom-screen-name)
  - [Using location heatmap](#using-location-heatmap)
- [Trouble shooting](#trouble-shooting)
  - [SDK does not record any logs](#sdk-does-not-record-any-logs)
  - [Show tap heatmaps without screen image](#show-tap-heatmaps-without-screen-image)
- [Other documents](#other-documents)
- [About UNCOVER TRUTH](#about-uncover-truth)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Compatibility

* iOS 7.0 or later (If you run application on iOS 6 or previous iOS version, SDK does not affect the behavior of application)
* Supported architectures below:
  * i386 & x86_64 (iOS simulator)
  * armv7
  * armv7s
  * arm64
* Supported devices below:
  * iPhone 4
  * iPhone 4s
  * iPhone 5
  * iPhone 5c
  * iPhone 5s
  * iPhone 6
  * iPhone 6+
* **iPad and iPod family are not supported**


# Installation

Write Podfile to your project.

```
pod 'Userdive-iOS-SDK', '~> 1.0'
```

Install pods.

```
pod install
```

And open workspace.

```
open YourProject.xcworkspace
```


# Understanding Userdive iOS SDK operation mode

SDK has 2 operation modes below:

* Developer mode
* Tracking mode


## Developer mode

**WARNING: DON'T USE THIS MODE FOR APPS IN PRODUCTION**

In developer mode, USERDIVE tracks some native views (UIViewController, UIActionSheet, UIAlertView etc.) for heatmap background image.
Confirmation dialog shows after every transition. Tap `Send` button to upload screen image on USERDIVE.


## Tracking mode

USERDIVE tracks user's gesture and transitions in tracking mode.
Those logs will be uploaded when the app enters to background.


# Integrate with your app

## Preparing integration

### Check your Team ID

Check your Team ID at [USERDIVE For Apps website](https://detector.userdive.com/en/apps/).

![team id](http://drive.google.com/uc?export=view&id=0B7UxsiswNc5_cHdTUGpOX0IyU2M)


### Check your Bundle ID

Check Bundle ID on Xcode and USERDIVE.

![bundle id settings on USERDIVE](http://drive.google.com/uc?export=view&id=0B7UxsiswNc5_WWVGaFdSMHNFMGs)

![bundle id on Xcode](http://drive.google.com/uc?export=view&id=0B7UxsiswNc5_Tno4VHA4Snh3alE)

## Capturing image

Before using userdive heatmap, capture the images of app view.
For capturing image, start USERDIVE iOS SDK with developer mode.


### Capture images when it detects view transitions

USERDIVE iOS SDK can automatically tracking user gesture, and view transitions,
if you use standard iOS UI components (UINavigationController, UITabBarController etc...).

Import USERDIVE iOS SDK header.

```objective-c
#import "Userdive.h"
```

Insert `[Userdive startDeveloperMode:<YOUR_TEAM_ID>]` into 
`AppDeletegate:application:didFinishLaunchingWithOptions:` with your Team ID.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  [Userdive setLogEnabled:YES];

  // START DEVELOPER MODE
  [Userdive startDeveloperMode:<your team id>];

  return YES;
}
```


### Capture images manually

You need to capture the images of app view manually
if you use custom view or 3rd party framework like a [Unity](https://unity3d.com/jp).

Import USERDIVE iOS SDK header.

```objective-c
#import "Userdive.h"
```

Insert `[Userdive startDeveloperMode:<YOUR_TEAM_ID>]` into 
`AppDeletegate:application:didFinishLaunchingWithOptions:` with your Team ID.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  [Userdive setLogEnabled:YES];

  // START DEVELOPER MODE WITHOUT TRACKERS
  [Userdive startDeveloperMode:<your team id> trackers:nil];

  return YES;
}
```

When you want to capture view is displayed, call the capture method.

Call `updateScreen` to prepare for capture the view.
When you call `updateScreen` again, upload the captured image (You need to call `updateScreen` twice).

```objective-c
- (void)viewDidAppear:(BOOL)animated
{
  [super viewDidAppear:animated];

  [Userdive updateScreen];
  [Userdive setScreenName:@"screen A"];
}
```


## Tracking gestures

### Automatically detect view transitions

USERDIVE iOS SDK can track user gesture and view transitions automatically.
To start tracking, call `startTrackingMode:` when initializing SDK.

Import USERDIVE iOS SDK header.

```objective-c
#import "Userdive.h"
```

Insert `[Userdive startTrackingMode:<YOUR_TEAM_ID>]` 
`AppDeletegate:application:didFinishLaunchingWithOptions:` with your Team ID.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	[Userdive setLogEnabled:YES];
	[Userdive startTrackingMode:<your team id>];  // <-- HERE

	return YES;
}
```

### Manually view transitions

In situations that have adopted a special view configuration
(non-standard view placement and third-party libraries, etc.), 
you might think that you want to switch the view tracking manually.

Import USERDIVE iOS SDK header.

```objective-c
#import "Userdive.h"
```

Insert `[Userdive startTrackingMode:<YOUR_TEAM_ID> trackers:nil]` into 
`AppDeletegate:application:didFinishLaunchingWithOptions:` with your Team ID.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  [Userdive setLogEnabled:YES];

  // START TRACKING MODE WITHOUT TRACKERS
  [Userdive startTrackingMode:<your team id> trackers:nil];

  return YES;
}
```

Call `updateScreen` to change tracking view instance.
And call `setScreenName` to set name of view.

```objective-c
- (void)viewDidAppear:(BOOL)animated
{
  [super viewDidAppear:animated];

  [Userdive updateScreen];
  [Userdive setScreenName:@"screen A"];
}
```


## Using custom parameters

You can set custom parameter for filterting on analytics view.
For instance, customer age, gender, living area ... etc.

Userdive can be accept custom parameters up to 5.
To set the parameters, enter any string to the method.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  // snip

  // custom parameter (up to 5)
  [Userdive setCustomField1:@"25"];    // user age
  [Userdive setCustomField2:@"male"];  // gender

  return YES;
}
```


## Using custom screen name

Set custom screen name in some ViewController.

```objective-c
- (void)viewDidLoad 
{
  [super viewDidLoad];

  [Userdive setScreenName:@"custom screen name"];  // custom screen name
}
```


## Using location heatmap

USERDIVE iOS SDK WILL NOT get user location automatically.
Set values from `CLLocation` object from delegate method of `CLLocationManagerDelegate` in your app.

To use location heatmap, call method below.

```objective-c
/**
 * Note:
 * USERDIVE iOS SDK does not link the CoreLocation framework.
 * Obtains the location information in the application,
 * you must pass the latitude and longitude to USERDIVE.
 */
- (void)locationManager:(CLLocationManager *)manager didUpdateLocations:(NSArray *)locations
{
    CLLocation *location = locations[0];

    [Userdive setLatitude:location.coordinate.latitude
                longitude:location.coordinate.longitude
       horizontalAccuracy:location.horizontalAccuracy
         verticalAccuracy:location.verticalAccuracy];
}
```


# Trouble shooting

## SDK does not record any logs

First, check your team id and app identifier.
Both values must match on detector.userdive.com.


## Show tap heatmaps without screen image

You must upload screen capture with developer mode.
Need to add `[Userdive startDeveloperMode:<your team id>]` into `AppDelegate.m` .


# Other documents

* [CHANGES](./CHANGES.md)
* [FAQ (In Japanese)](./FAQ.ja.md)


# About UNCOVER TRUTH

UNCOVER TRUTH Inc. is the Japan No.1 UI/UX analytics and consulting company providing an analytics tool called "USERDIVE for Apps".
In spite of launched service within a year, more 200 companies utilize this service to improve their UI/UX. Based on our achievements and experiences in Japan, we want to share our experiences to improve all companies who have problems with their UI/UX. Also, we want to make user-friendly services more and more in the world. USERDIVE for Apps is the best UI/UX analytics tool, which enables to confirm every single users' transition in all pages, content read during the stay, by HEAT MAPS, FUNNEL ANALYTICS and PLAY BACK. This UX analytics tool can achieve more effective improvements that are better than the pervious experiences of designers or developers.
