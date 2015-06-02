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


# Understanding Userdive iOS SDK

SDK has 2 operation modes below:

* Developer mode
* Tracking mode


## Developer mode

**WARNING: DON'T USE THIS FOR PRODUCTION APPS**

Userdive tracks some native views (UIViewController, UIActionSheet, UIAlertView etc.) for heatmap base image in developer mode.
Confirmation dialog shows after every transitions. To tap *send* button, upload to userdive screen image immediately.


## Tracking mode

Userdive tracks user's gesture, transisions in tracking mode.
Those logs will be uploaded when app entering to background.


# Integrate with your app

## Check your Team ID

Check your Team ID at [USERDIVE For Apps website](https://detector.userdive.com/ja/apps/).


## Implementation

Import Userdive header.

```
#import "Userdive.h"
```

Insert `[Userdive startTrackingMode:<YOUR_TEAM_ID>]` or `[Userdive startDeveloperMode:<YOUR_TEAM_ID>]` into `AppDeletegate:application:didFinishLaunchingWithOptions:`.

```objective-c
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  [Userdive startTrackingMode:<your team id>];  // <-- HERE
  return YES;
}
```


# Trouble shooting

* Check app logs
* Check your team id and app bundle identifier


# About UNCOVER TRUTH

UNCOVER TRUTH Inc. is the Japan No.1 UI/UX anayltics consulting company provide
a analytics tool called "USERDIVE for Apps".

In spite of launched service within a year, more 200 companies utilize the
service and improve their UI/UX better. Based on our achievement and experiences
in Japan, we want to share our experiences to improve all companies who have
problems with their UI/UX. Also, we want to make user-friendly services more and
more in the world. USERDIVE for Apps is the best UI/UX analytics tool, which be
able to confirm every single users' all of page transition page staying time
read content by HEAT MAPS, FUNNEL ANALYTICS and PLAY BACK. Based on UX analytics
can achieve more effective improvement which is better than the pervious
experience of designers or developers.
