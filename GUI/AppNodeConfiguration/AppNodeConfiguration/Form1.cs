using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

 
namespace AppNodeConfiguration
{
    public partial class Form1 : Form
    {
        string dataIn;
        string dataOut = "NTT \r\n";
        public Form1()
        {
            InitializeComponent();
        }

        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.PortName = cBoxComPort.Text;
                serialPort1.BaudRate = Convert.ToInt32(cBoxBaudrate.Text);
                serialPort1.DataBits = Convert.ToInt32(cBoxDatabits.Text);
                serialPort1.StopBits = (StopBits)Enum.Parse(typeof(StopBits), cBoxStopbits.Text);

                serialPort1.Parity = (Parity)Enum.Parse(typeof(Parity), cBoxParity.Text);
                serialPort1.Open();
                prgBarLoad.Value = 100;

            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                

            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();
            cBoxComPort.Items.AddRange(ports);
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
           if (serialPort1.IsOpen)
            {
                serialPort1.Close();
                prgBarLoad.Value = 0;
            }
        }

        private void btnSend_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                dataOut = tBoxSend.Text;
                serialPort1.WriteLine(dataOut);
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void label10_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void comboBox10_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void label12_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {

        }

        private void comboBox6_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            dataIn = serialPort1.ReadExisting();       
            this.Invoke(new EventHandler(showdata));
        }

        private void showdata(object sender, EventArgs e)
        {
            tBoxRecv.Text +=dataIn;
        }

        private void tBoxSend_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void tBoxSend_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Enter)
            {
                if (serialPort1.IsOpen)
                {
                    dataOut = tBoxSend.Text;
                    serialPort1.WriteLine(dataOut);

                    tBoxSend.Text = tBoxSend.Text.Remove(0);
                }
            }
        }

        private void tBoxRecv_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
