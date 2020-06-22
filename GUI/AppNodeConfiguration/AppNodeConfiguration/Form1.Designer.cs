namespace AppNodeConfiguration
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.cBoxParity = new System.Windows.Forms.ComboBox();
            this.cBoxStopbits = new System.Windows.Forms.ComboBox();
            this.cBoxDatabits = new System.Windows.Forms.ComboBox();
            this.cBoxBaudrate = new System.Windows.Forms.ComboBox();
            this.cBoxComPort = new System.Windows.Forms.ComboBox();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.Manual = new System.Windows.Forms.GroupBox();
            this.tBoxSend = new System.Windows.Forms.TextBox();
            this.prgBarLoad = new System.Windows.Forms.ProgressBar();
            this.btnSend = new System.Windows.Forms.Button();
            this.tBoxRecv = new System.Windows.Forms.TextBox();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnOpen = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.btnSetMB = new System.Windows.Forms.Button();
            this.btnGetMB = new System.Windows.Forms.Button();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.cBoxMbMode = new System.Windows.Forms.ComboBox();
            this.tBoxSid = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.cBoxPari = new System.Windows.Forms.ComboBox();
            this.cBoxSB = new System.Windows.Forms.ComboBox();
            this.cBoxDb = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.cBoxMbBaud = new System.Windows.Forms.ComboBox();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.button3 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.label12 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.label17 = new System.Windows.Forms.Label();
            this.tBoxAppKey = new System.Windows.Forms.TextBox();
            this.tBoxAppEUI = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.tBoxDevEUI = new System.Windows.Forms.TextBox();
            this.label13 = new System.Windows.Forms.Label();
            this.cBoxLrMode = new System.Windows.Forms.ComboBox();
            this.label14 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.Manual.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.cBoxParity);
            this.groupBox1.Controls.Add(this.cBoxStopbits);
            this.groupBox1.Controls.Add(this.cBoxDatabits);
            this.groupBox1.Controls.Add(this.cBoxBaudrate);
            this.groupBox1.Controls.Add(this.cBoxComPort);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(27, 22);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox1.Size = new System.Drawing.Size(279, 258);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Com Port Control";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(12, 171);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(52, 20);
            this.label5.TabIndex = 10;
            this.label5.Text = "Parity";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 137);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(75, 20);
            this.label4.TabIndex = 9;
            this.label4.Text = "Stop bits";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 103);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(77, 20);
            this.label3.TabIndex = 8;
            this.label3.Text = "Data bits";
            this.label3.Click += new System.EventHandler(this.label3_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 68);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(77, 20);
            this.label2.TabIndex = 7;
            this.label2.Text = "Baudrate";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(80, 20);
            this.label1.TabIndex = 6;
            this.label1.Text = "Com Port";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // cBoxParity
            // 
            this.cBoxParity.FormattingEnabled = true;
            this.cBoxParity.Items.AddRange(new object[] {
            "Odd",
            "Even",
            "None"});
            this.cBoxParity.Location = new System.Drawing.Point(131, 162);
            this.cBoxParity.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxParity.Name = "cBoxParity";
            this.cBoxParity.Size = new System.Drawing.Size(121, 28);
            this.cBoxParity.TabIndex = 5;
            this.cBoxParity.Text = "None";
            // 
            // cBoxStopbits
            // 
            this.cBoxStopbits.FormattingEnabled = true;
            this.cBoxStopbits.Items.AddRange(new object[] {
            "1",
            "2"});
            this.cBoxStopbits.Location = new System.Drawing.Point(131, 129);
            this.cBoxStopbits.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxStopbits.Name = "cBoxStopbits";
            this.cBoxStopbits.Size = new System.Drawing.Size(121, 28);
            this.cBoxStopbits.TabIndex = 4;
            this.cBoxStopbits.Text = "1";
            // 
            // cBoxDatabits
            // 
            this.cBoxDatabits.FormattingEnabled = true;
            this.cBoxDatabits.Items.AddRange(new object[] {
            "7",
            "8"});
            this.cBoxDatabits.Location = new System.Drawing.Point(131, 95);
            this.cBoxDatabits.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxDatabits.Name = "cBoxDatabits";
            this.cBoxDatabits.Size = new System.Drawing.Size(121, 28);
            this.cBoxDatabits.TabIndex = 3;
            this.cBoxDatabits.Text = "8";
            this.cBoxDatabits.SelectedIndexChanged += new System.EventHandler(this.comboBox3_SelectedIndexChanged);
            // 
            // cBoxBaudrate
            // 
            this.cBoxBaudrate.FormattingEnabled = true;
            this.cBoxBaudrate.Items.AddRange(new object[] {
            "4800",
            "57600",
            "9600",
            "115200"});
            this.cBoxBaudrate.Location = new System.Drawing.Point(131, 60);
            this.cBoxBaudrate.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxBaudrate.Name = "cBoxBaudrate";
            this.cBoxBaudrate.Size = new System.Drawing.Size(121, 28);
            this.cBoxBaudrate.TabIndex = 2;
            this.cBoxBaudrate.Text = "115200";
            // 
            // cBoxComPort
            // 
            this.cBoxComPort.FormattingEnabled = true;
            this.cBoxComPort.Location = new System.Drawing.Point(131, 26);
            this.cBoxComPort.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxComPort.Name = "cBoxComPort";
            this.cBoxComPort.Size = new System.Drawing.Size(121, 28);
            this.cBoxComPort.TabIndex = 1;
            // 
            // Manual
            // 
            this.Manual.Controls.Add(this.tBoxSend);
            this.Manual.Controls.Add(this.prgBarLoad);
            this.Manual.Controls.Add(this.btnSend);
            this.Manual.Controls.Add(this.tBoxRecv);
            this.Manual.Controls.Add(this.btnClose);
            this.Manual.Controls.Add(this.btnOpen);
            this.Manual.Location = new System.Drawing.Point(27, 287);
            this.Manual.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Manual.Name = "Manual";
            this.Manual.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Manual.Size = new System.Drawing.Size(279, 367);
            this.Manual.TabIndex = 11;
            this.Manual.TabStop = false;
            this.Manual.Text = "Manual";
            // 
            // tBoxSend
            // 
            this.tBoxSend.Location = new System.Drawing.Point(13, 110);
            this.tBoxSend.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tBoxSend.Multiline = true;
            this.tBoxSend.Name = "tBoxSend";
            this.tBoxSend.Size = new System.Drawing.Size(239, 107);
            this.tBoxSend.TabIndex = 14;
            this.tBoxSend.TextChanged += new System.EventHandler(this.tBoxSend_TextChanged);
            this.tBoxSend.KeyDown += new System.Windows.Forms.KeyEventHandler(this.tBoxSend_KeyDown);
            // 
            // prgBarLoad
            // 
            this.prgBarLoad.Location = new System.Drawing.Point(13, 62);
            this.prgBarLoad.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.prgBarLoad.Name = "prgBarLoad";
            this.prgBarLoad.Size = new System.Drawing.Size(153, 31);
            this.prgBarLoad.TabIndex = 15;
            // 
            // btnSend
            // 
            this.btnSend.Location = new System.Drawing.Point(173, 14);
            this.btnSend.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnSend.Name = "btnSend";
            this.btnSend.Size = new System.Drawing.Size(100, 79);
            this.btnSend.TabIndex = 14;
            this.btnSend.Text = "Send Data";
            this.btnSend.UseVisualStyleBackColor = true;
            this.btnSend.Click += new System.EventHandler(this.btnSend_Click);
            // 
            // tBoxRecv
            // 
            this.tBoxRecv.Location = new System.Drawing.Point(13, 240);
            this.tBoxRecv.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tBoxRecv.Multiline = true;
            this.tBoxRecv.Name = "tBoxRecv";
            this.tBoxRecv.Size = new System.Drawing.Size(239, 106);
            this.tBoxRecv.TabIndex = 12;
            this.tBoxRecv.TextChanged += new System.EventHandler(this.tBoxRecv_TextChanged);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(93, 21);
            this.btnClose.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 34);
            this.btnClose.TabIndex = 13;
            this.btnClose.Text = "Close";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnOpen
            // 
            this.btnOpen.Location = new System.Drawing.Point(13, 21);
            this.btnOpen.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnOpen.Name = "btnOpen";
            this.btnOpen.Size = new System.Drawing.Size(73, 34);
            this.btnOpen.TabIndex = 12;
            this.btnOpen.Text = "Open";
            this.btnOpen.UseVisualStyleBackColor = true;
            this.btnOpen.Click += new System.EventHandler(this.button1_Click);
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.btnSetMB);
            this.groupBox2.Controls.Add(this.btnGetMB);
            this.groupBox2.Controls.Add(this.label11);
            this.groupBox2.Controls.Add(this.label10);
            this.groupBox2.Controls.Add(this.cBoxMbMode);
            this.groupBox2.Controls.Add(this.tBoxSid);
            this.groupBox2.Controls.Add(this.label7);
            this.groupBox2.Controls.Add(this.label8);
            this.groupBox2.Controls.Add(this.label9);
            this.groupBox2.Controls.Add(this.cBoxPari);
            this.groupBox2.Controls.Add(this.cBoxSB);
            this.groupBox2.Controls.Add(this.cBoxDb);
            this.groupBox2.Controls.Add(this.label6);
            this.groupBox2.Controls.Add(this.cBoxMbBaud);
            this.groupBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox2.Location = new System.Drawing.Point(329, 22);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox2.Size = new System.Drawing.Size(547, 258);
            this.groupBox2.TabIndex = 11;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Modbus Slave";
            // 
            // btnSetMB
            // 
            this.btnSetMB.Location = new System.Drawing.Point(307, 145);
            this.btnSetMB.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnSetMB.Name = "btnSetMB";
            this.btnSetMB.Size = new System.Drawing.Size(100, 79);
            this.btnSetMB.TabIndex = 38;
            this.btnSetMB.Text = "Set";
            this.btnSetMB.UseVisualStyleBackColor = true;
            this.btnSetMB.Click += new System.EventHandler(this.button5_Click);
            // 
            // btnGetMB
            // 
            this.btnGetMB.Location = new System.Drawing.Point(307, 26);
            this.btnGetMB.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnGetMB.Name = "btnGetMB";
            this.btnGetMB.Size = new System.Drawing.Size(100, 66);
            this.btnGetMB.TabIndex = 27;
            this.btnGetMB.Text = "Get";
            this.btnGetMB.UseVisualStyleBackColor = true;
            this.btnGetMB.Click += new System.EventHandler(this.button4_Click);
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(20, 199);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(72, 20);
            this.label11.TabIndex = 25;
            this.label11.Text = "Slave ID";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(20, 34);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(50, 20);
            this.label10.TabIndex = 24;
            this.label10.Text = "Mode";
            this.label10.Click += new System.EventHandler(this.label10_Click);
            // 
            // cBoxMbMode
            // 
            this.cBoxMbMode.FormattingEnabled = true;
            this.cBoxMbMode.Items.AddRange(new object[] {
            "RTU",
            "ASCII"});
            this.cBoxMbMode.Location = new System.Drawing.Point(163, 26);
            this.cBoxMbMode.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxMbMode.Name = "cBoxMbMode";
            this.cBoxMbMode.Size = new System.Drawing.Size(121, 28);
            this.cBoxMbMode.TabIndex = 23;
            this.cBoxMbMode.Text = "RTU";
            this.cBoxMbMode.SelectedIndexChanged += new System.EventHandler(this.comboBox5_SelectedIndexChanged);
            // 
            // tBoxSid
            // 
            this.tBoxSid.Location = new System.Drawing.Point(163, 197);
            this.tBoxSid.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tBoxSid.Name = "tBoxSid";
            this.tBoxSid.Size = new System.Drawing.Size(121, 27);
            this.tBoxSid.TabIndex = 22;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(20, 171);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(52, 20);
            this.label7.TabIndex = 21;
            this.label7.Text = "Parity";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(20, 137);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(75, 20);
            this.label8.TabIndex = 20;
            this.label8.Text = "Stop bits";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(20, 103);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(77, 20);
            this.label9.TabIndex = 19;
            this.label9.Text = "Data bits";
            // 
            // cBoxPari
            // 
            this.cBoxPari.FormattingEnabled = true;
            this.cBoxPari.Items.AddRange(new object[] {
            "Odd",
            "Even",
            "None"});
            this.cBoxPari.Location = new System.Drawing.Point(163, 162);
            this.cBoxPari.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxPari.Name = "cBoxPari";
            this.cBoxPari.Size = new System.Drawing.Size(121, 28);
            this.cBoxPari.TabIndex = 18;
            this.cBoxPari.Text = "None";
            this.cBoxPari.SelectedIndexChanged += new System.EventHandler(this.cBoxPari_SelectedIndexChanged);
            // 
            // cBoxSB
            // 
            this.cBoxSB.FormattingEnabled = true;
            this.cBoxSB.Items.AddRange(new object[] {
            "1",
            "2"});
            this.cBoxSB.Location = new System.Drawing.Point(163, 129);
            this.cBoxSB.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxSB.Name = "cBoxSB";
            this.cBoxSB.Size = new System.Drawing.Size(121, 28);
            this.cBoxSB.TabIndex = 17;
            this.cBoxSB.Text = "1";
            // 
            // cBoxDb
            // 
            this.cBoxDb.FormattingEnabled = true;
            this.cBoxDb.Items.AddRange(new object[] {
            "7",
            "8"});
            this.cBoxDb.Location = new System.Drawing.Point(163, 94);
            this.cBoxDb.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxDb.Name = "cBoxDb";
            this.cBoxDb.Size = new System.Drawing.Size(121, 28);
            this.cBoxDb.TabIndex = 16;
            this.cBoxDb.Text = "8";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(20, 68);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(77, 20);
            this.label6.TabIndex = 15;
            this.label6.Text = "Baudrate";
            // 
            // cBoxMbBaud
            // 
            this.cBoxMbBaud.FormattingEnabled = true;
            this.cBoxMbBaud.Items.AddRange(new object[] {
            "4800",
            "57600",
            "9600",
            "115200"});
            this.cBoxMbBaud.Location = new System.Drawing.Point(163, 60);
            this.cBoxMbBaud.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxMbBaud.Name = "cBoxMbBaud";
            this.cBoxMbBaud.Size = new System.Drawing.Size(121, 28);
            this.cBoxMbBaud.TabIndex = 14;
            this.cBoxMbBaud.Text = "115200";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(307, 257);
            this.button1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(100, 79);
            this.button1.TabIndex = 15;
            this.button1.Text = "Set";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(163, 257);
            this.button2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(100, 79);
            this.button2.TabIndex = 26;
            this.button2.Text = "Get";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.button3);
            this.groupBox3.Controls.Add(this.button2);
            this.groupBox3.Controls.Add(this.textBox1);
            this.groupBox3.Controls.Add(this.button1);
            this.groupBox3.Controls.Add(this.textBox5);
            this.groupBox3.Controls.Add(this.label12);
            this.groupBox3.Controls.Add(this.label16);
            this.groupBox3.Controls.Add(this.textBox6);
            this.groupBox3.Controls.Add(this.label17);
            this.groupBox3.Controls.Add(this.tBoxAppKey);
            this.groupBox3.Controls.Add(this.tBoxAppEUI);
            this.groupBox3.Controls.Add(this.label15);
            this.groupBox3.Controls.Add(this.label18);
            this.groupBox3.Controls.Add(this.tBoxDevEUI);
            this.groupBox3.Controls.Add(this.label13);
            this.groupBox3.Controls.Add(this.cBoxLrMode);
            this.groupBox3.Controls.Add(this.label14);
            this.groupBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox3.Location = new System.Drawing.Point(329, 287);
            this.groupBox3.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Padding = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.groupBox3.Size = new System.Drawing.Size(547, 367);
            this.groupBox3.TabIndex = 13;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "LoraWAN";
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(20, 257);
            this.button3.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(100, 79);
            this.button3.TabIndex = 37;
            this.button3.Text = "Join";
            this.button3.UseVisualStyleBackColor = true;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(163, 224);
            this.textBox1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(377, 27);
            this.textBox1.TabIndex = 36;
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(163, 158);
            this.textBox5.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(377, 27);
            this.textBox5.TabIndex = 30;
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(19, 194);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(87, 20);
            this.label12.TabIndex = 35;
            this.label12.Text = "App S Key";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(20, 226);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(79, 20);
            this.label16.TabIndex = 29;
            this.label16.Text = "Dev Addr";
            // 
            // textBox6
            // 
            this.textBox6.Location = new System.Drawing.Point(163, 191);
            this.textBox6.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(377, 27);
            this.textBox6.TabIndex = 34;
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(17, 165);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(80, 20);
            this.label17.TabIndex = 33;
            this.label17.Text = "NwkSKey";
            // 
            // tBoxAppKey
            // 
            this.tBoxAppKey.Location = new System.Drawing.Point(163, 92);
            this.tBoxAppKey.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tBoxAppKey.Name = "tBoxAppKey";
            this.tBoxAppKey.Size = new System.Drawing.Size(377, 27);
            this.tBoxAppKey.TabIndex = 28;
            this.tBoxAppKey.TextChanged += new System.EventHandler(this.textBox4_TextChanged);
            // 
            // tBoxAppEUI
            // 
            this.tBoxAppEUI.Location = new System.Drawing.Point(163, 126);
            this.tBoxAppEUI.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tBoxAppEUI.Name = "tBoxAppEUI";
            this.tBoxAppEUI.Size = new System.Drawing.Size(377, 27);
            this.tBoxAppEUI.TabIndex = 32;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(20, 98);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(71, 20);
            this.label15.TabIndex = 27;
            this.label15.Text = "App Key";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(20, 132);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(70, 20);
            this.label18.TabIndex = 31;
            this.label18.Text = "App EUI";
            // 
            // tBoxDevEUI
            // 
            this.tBoxDevEUI.Location = new System.Drawing.Point(163, 59);
            this.tBoxDevEUI.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tBoxDevEUI.Name = "tBoxDevEUI";
            this.tBoxDevEUI.Size = new System.Drawing.Size(378, 27);
            this.tBoxDevEUI.TabIndex = 26;
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(20, 34);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(50, 20);
            this.label13.TabIndex = 24;
            this.label13.Text = "Mode";
            // 
            // cBoxLrMode
            // 
            this.cBoxLrMode.FormattingEnabled = true;
            this.cBoxLrMode.Items.AddRange(new object[] {
            "OTAA",
            "ADP"});
            this.cBoxLrMode.Location = new System.Drawing.Point(163, 26);
            this.cBoxLrMode.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cBoxLrMode.Name = "cBoxLrMode";
            this.cBoxLrMode.Size = new System.Drawing.Size(121, 28);
            this.cBoxLrMode.TabIndex = 23;
            this.cBoxLrMode.Text = "OTAA";
            this.cBoxLrMode.SelectedIndexChanged += new System.EventHandler(this.comboBox6_SelectedIndexChanged);
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(20, 66);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(71, 20);
            this.label14.TabIndex = 21;
            this.label14.Text = "Dev EUI";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(925, 666);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.Manual);
            this.Controls.Add(this.groupBox1);
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.Name = "Form1";
            this.Text = "C# App Node Configuration";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.Manual.ResumeLayout(false);
            this.Manual.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.ComboBox cBoxParity;
        private System.Windows.Forms.ComboBox cBoxStopbits;
        private System.Windows.Forms.ComboBox cBoxDatabits;
        private System.Windows.Forms.ComboBox cBoxBaudrate;
        private System.Windows.Forms.ComboBox cBoxComPort;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.GroupBox Manual;
        private System.Windows.Forms.Button btnSend;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.Button btnOpen;
        private System.Windows.Forms.ProgressBar prgBarLoad;
        private System.Windows.Forms.TextBox tBoxRecv;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox tBoxSid;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ComboBox cBoxPari;
        private System.Windows.Forms.ComboBox cBoxSB;
        private System.Windows.Forms.ComboBox cBoxDb;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox cBoxMbBaud;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.ComboBox cBoxMbMode;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.ComboBox cBoxLrMode;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.TextBox tBoxAppKey;
        private System.Windows.Forms.TextBox tBoxAppEUI;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.TextBox tBoxDevEUI;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.TextBox tBoxSend;
        private System.Windows.Forms.Button btnSetMB;
        private System.Windows.Forms.Button btnGetMB;
    }
}

