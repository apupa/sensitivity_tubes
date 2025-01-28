function robot = import_model(n)

% Link 1
link{1}.a = 0;
link{1}.alpha = pi/2;
link{1}.d = 0.1625;
link{1}.theta = 0;
link{1}.mdh = 0;
link{1}.I = [0, 0, 0, 0, 0, 0];
link{1}.r = [0, -0.02561, 0.00193];
link{1}.m = 3.761;
link{1}.qlim = [-2*pi, 2*pi];

% Link 2
link{2}.a = -0.425;
link{2}.alpha = 0;
link{2}.d = 0;
link{2}.theta = 0;
link{2}.mdh = 0;
link{2}.I = [0, 0, 0, 0, 0, 0];
link{2}.r = [0.2125, 0, 0.11336];
link{2}.m = 8.058;
link{2}.qlim = [-2*pi, 2*pi];

% Link 3
link{3}.a = -0.3922;
link{3}.alpha = 0;
link{3}.d = 0;
link{3}.theta = 0;
link{3}.mdh = 0;
link{3}.I = [0, 0, 0, 0, 0, 0];
link{3}.r = [0.15, 0, 0.0265];
link{3}.m = 2.846;
link{3}.qlim = [-2*pi, 2*pi];

% Link 4
link{4}.a = 0;
link{4}.alpha = pi/2;
link{4}.d = 0.1333;
link{4}.theta = 0;
link{4}.mdh = 0;
link{4}.I = [0, 0, 0, 0, 0, 0];
link{4}.r = [0, -0.0018, 0.01634];
link{4}.m = 1.37;
link{4}.qlim = [-2*pi, 2*pi];

% Link 5
link{5}.a = 0;
link{5}.alpha = -pi/2;
link{5}.d = 0.0997;
link{5}.theta = 0;
link{5}.mdh = 0;
link{5}.I = [0, 0, 0, 0, 0, 0];
link{5}.r = [0, 0.0018, 0.01634];
link{5}.m = 1.3;
link{5}.qlim = [-2*pi, 2*pi];

% Link 6
link{6}.a = 0;
link{6}.alpha = 0;
link{6}.d = 0.0996;
link{6}.theta = 0;
link{6}.mdh = 0;
link{6}.I = [0, 0, 0.0002, 0, 0, 0];
link{6}.r = [0, 0, -0.001159];
link{6}.m = 0.365;
link{6}.qlim = [-2*pi, 2*pi];


for i=1:n
    % Links(i) = Link();
    Links(i).a = link{i}.a;
    Links(i).alpha = link{i}.alpha;
    Links(i).d = link{i}.d;
    Links(i).theta = link{i}.theta;
    Links(i).mdh = link{i}.mdh;
    Links(i).qlim = link{i}.qlim;

    Links(i).m = link{i}.m;
    Links(i).r = link{i}.r;
    v = link{i}.I;
    Links(i).I = [v(1) v(4) v(6);
                  v(4) v(2) v(5);
                  v(6) v(5) v(3)];
    % Links(i).I = link{i}.I;
    Links(i).offset = 0;
end

% robot = SerialLink(Links);
robot.links = Links;
robot.name = "ur";
end