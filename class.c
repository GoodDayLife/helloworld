using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Mail;
using System.Configuration;


namespace ConsoleSendMail
{
	class Program
	{
		static void Main(string[] args)
		{
			string host = "192.168.20.40"; // 邮件服务器
			string userName = "sfc@it.luxshare-ict.com";
			string password = "Share888";
			string mailFrom = "sfc@it.luxshare-ict.com";
			string mailTo = "zhenhua.li@luxshare-ict.com";

			string subject = "Test mail suject ";//邮件的主题
			string body = "TEST mail Body";//发送的邮件正文 

			SmtpClient client = new SmtpClient(host);
			client.DeliveryMethod = SmtpDeliveryMethod.Network;
			client.UseDefaultCredentials = true;
			client.Credentials = new System.Net.NetworkCredential(userName, password);//用户名、密码
			System.Net.Mail.MailMessage msg = new System.Net.Mail.MailMessage();
			msg.From = new MailAddress(mailFrom);
			msg.To.Add(mailTo);
			msg.CC.Add(strcc);

			msg.Subject = subject;//邮件标题
			msg.Body = body;//邮件内容
			msg.BodyEncoding = System.Text.Encoding.UTF8;//邮件内容编码
			msg.IsBodyHtml = true;//是否是HTML邮件
			msg.Priority = MailPriority.High;//邮件优先级 

			client.Send(msg);

		}
	}
}

