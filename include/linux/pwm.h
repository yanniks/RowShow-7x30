#ifndef __LINUX_PWM_H
#define __LINUX_PWM_H

struct pwm_device;

<<<<<<< HEAD
/* Add __weak functions to support PWM */

/*
 * pwm_request - request a PWM device
 */
struct pwm_device __weak *pwm_request(int pwm_id, const char *label);
=======
/*
 * pwm_request - request a PWM device
 */
struct pwm_device *pwm_request(int pwm_id, const char *label);
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d

/*
 * pwm_free - free a PWM device
 */
<<<<<<< HEAD
void __weak pwm_free(struct pwm_device *pwm);
=======
void pwm_free(struct pwm_device *pwm);
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d

/*
 * pwm_config - change a PWM device configuration
 */
<<<<<<< HEAD
int __weak pwm_config(struct pwm_device *pwm, int duty_ns, int period_ns);
=======
int pwm_config(struct pwm_device *pwm, int duty_ns, int period_ns);
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d

/*
 * pwm_enable - start a PWM output toggling
 */
<<<<<<< HEAD
int __weak pwm_enable(struct pwm_device *pwm);
=======
int pwm_enable(struct pwm_device *pwm);
>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d

/*
 * pwm_disable - stop a PWM output toggling
 */
<<<<<<< HEAD
void __weak pwm_disable(struct pwm_device *pwm);

int pm8xxx_pwm_lut_config(struct pwm_device *pwm, int period_us,
			  int duty_pct[], int duty_time_ms, int start_idx,
			  int idx_len, int pause_lo, int pause_hi, int flags);

int pm8xxx_pwm_lut_enable(struct pwm_device *pwm, int start);
=======
void pwm_disable(struct pwm_device *pwm);

>>>>>>> ae02c5a7cd1ed15da0976a44b8d0da4ad5c0975d
#endif /* __LINUX_PWM_H */
