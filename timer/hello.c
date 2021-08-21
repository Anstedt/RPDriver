#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/timer.h>

struct timer_list led_timer;
char kbledstatus = 0;
int status = 0;

static void hello_timer(struct timer_list *t)
{
  printk("jiffies + HZ = %ld + %d\n", jiffies, HZ);
  
  led_timer.expires = jiffies + HZ;
  add_timer(&led_timer);
}

static int __init hello_init(void)
{
  printk("Hello Timer\n");
  
  timer_setup(&led_timer, hello_timer, (unsigned int) &kbledstatus);
  led_timer.expires = jiffies + HZ;
  add_timer(&led_timer);
  
  return 0;
}

static void __exit hello_exit(void)
{
  del_timer(&led_timer);
  printk("Hello Timer Gone\n");
}

module_init(hello_init);
module_exit(hello_exit);
