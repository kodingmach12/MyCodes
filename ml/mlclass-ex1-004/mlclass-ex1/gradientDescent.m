function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESENT(X, y, theta, alpha, num_iters) updates theta by
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

for iter = 1:num_iters

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta.
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %
    cost = computeCost(X,y,theta);
    disp(cost);
    % sigmaValue = 0;
    % for i = 1:m,
    %   sigmaValue = sigmaValue + ( X*theta - y );
    % % disp(length(sigmaValue));
    % temp0 = theta(1) - (alpha/m).* sigmaValue;

    % sigmaValue1 = 0;
    % for i = 1:m,
    %   sigmaValue1 = sigmaValue1 + ( X*theta - y ).*x(i,1);

    % temp1 = theta(2) - (alpha/m).* sigmaValue;
    % theta(1) = temp1;
    % theta(2) = temp2;

    tmpTheta1= theta(1) - alpha * (1/m) * ((X * theta) - y)' * X(:, 1);
    tmpTheta2= theta(2) - alpha * (1/m) * ((X * theta) - y)' * X(:, 2);
    theta(1)=tmpTheta1;
    theta(2)=tmpTheta2;
    % thetaj = thetaj - alpha/m Sigma (hx - y)x
    % ============================================================

    % Save the cost J in every iteration
    J_history(iter) = computeCost(X, y, theta);

end

end

