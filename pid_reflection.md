Reflection for PID Controller Project
=====================================

Describe the effect each of the P, I, D components had in your implementation.
------------------------------------------------------------------------------

- P component: This component contributes to the main steering angle. The parameter `Kp` controls the ratio of main steering angle to the cross-track error (`CTE`). The greater the value of `Kp`, the more sensitive the controller is to the same value of `CTE`. The value being too large causes the vehicle to make a lot of extreme steers which introduces great fluctuations. On the other hand, The value being too small leads to reduced ability of track recovery, which causes the vehicle to go off the road easily as a result of slow steering at a relatively high speed.

- I component: This component contributes to the complementory steering angle which aims to reduce constant margin from the track introduced by systematic biases. This is achieved by considering the accumulated history of `CTE` (`aCTE`). The parameter `Ki` controls the ratio of complementory steering angle to `aCTE`. As the vehicle stays close to the track, the `aCTE` does not change much, thus `Ki * aCTE` will stay contant, which indicates no further compensation is required. On the other hand, As the vehicle stays away from the track persistently, `aCTE` accumulates which introduces increased compensation. The value `Ki` being too high makes the vehicle more likely to overshoot as the contribution of this component can easily override the main steering angle due to the quick growth of `aCTE`. And `Ki` being too small would introduce a long bias compensation time.

- D component `Kd`: `Kd` controls the ratio of the counter steering to the change in `CTE`. If the `CTE` is reduced in magnitude in comparison to the last one, the steering angle toward the track is diminished, which mitigates overshooting. On the other hand, if the `CTE` is increased in magnitude (e.g. when overshooting, passing curves, etc), the steering angle toward the track is increased, which supports stronger track recovery. The value being too large will override the recovery angle and diverts the vehicle from the track. In contrast, the value being too small would introduce more overshooting.

Describe how the final hyperparameters were chosen.
---------------------------------------------------

- The final hyperparameters were chosen manual using the above ideas. The parameters were first set to zero, and the speed is kept constant at around 13 mph. Then, `Kp` is first increased to try to let the car stay in the middle on average. After that, `Kd` is increased to a point where the drive is sufficiently smooth without much fluctuations. Finally, the `Ki` is increased at a very low rate to reduce the effect of systematic biases.

- The hyperparameters are chosen to be `Kp = 0.63, Ki = 0.003, Kd = 2` (see `main.cpp`).
